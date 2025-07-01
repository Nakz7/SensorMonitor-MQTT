#ifndef MOSQQTCLIENT_H
#define MOSQQTCLIENT_H

/**
 * \file MosqQtClient.h
 * \brief Pont Qt <-> libmosquittopp thread-safe
 */

#pragma once

#include <QObject>
#include <mosquittopp.h>

namespace Sensor
{
namespace Mqtt
{
/**
 * \class MosqQtClient
 * \brief Wrapper QObject + mosquittopp ; publie des signaux Qt
 *
 * La boucle réseau Mosquitto tourne dans un thread interne (loop_start())
 * Les callbacks C sont relayés dans le thread Qt via QMetaObject::invokeMethod
 */
class MosqQtClient : public QObject
                   , public mosqpp::mosquittopp
{
    Q_OBJECT

public:
    explicit MosqQtClient(const QString &clientId,
                          QObject      *parent = nullptr);

    void subscribeTopic(const QByteArray &topic, int qos = 1);
    void publishMessage(const QByteArray &topic,
                        const QByteArray &payload,
                        int  qos    = 1,
                        bool retain = true);

signals:
    void connected();
    void disconnected();
    void messageReceived(QByteArray topic, QByteArray payload);

protected:                 // callbacks Mosquitto
    void on_connect(int rc) override;
    void on_disconnect(int rc) override;
    void on_message(const mosquitto_message *msg) override;
};
} // namespace Mqtt
} // namespace Sensor


#endif // MOSQQTCLIENT_H
