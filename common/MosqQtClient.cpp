/**
 * \file MosqQtClient.cpp
 * \brief Implémentation de Sensor::Mqtt::MosqQtClient.
 */

#include "MosqQtClient.h"
#include <QMetaObject>

using namespace Sensor::Mqtt;

MosqQtClient::MosqQtClient(const QString &clientId, QObject *parent)
    : QObject(parent)
    , mosquittopp(clientId.toLatin1().constData(), true)
{
    mosqpp::lib_init();
    connect_async("localhost", 1883, 60);
    loop_start();
}

void MosqQtClient::subscribeTopic(const QByteArray &topic, int qos)
{
    subscribe(nullptr, topic.constData(), qos);
}

void MosqQtClient::publishMessage(const QByteArray &topic,
                                  const QByteArray &payload,
                                  int qos,
                                  bool retain)
{
    publish(nullptr, topic.constData(),
            static_cast<int>(payload.size()), payload.constData(),
            qos, retain);
}

// ------------------------------------------------------------------
// Callbacks  (thread Mosquitto)  ->  relai Qt
// ------------------------------------------------------------------
void MosqQtClient::on_connect(int rc)
{
    QMetaObject::invokeMethod(this, [this, rc]()
    {
        rc == 0 ? emit connected()
                : emit disconnected();
    }, Qt::QueuedConnection);
}

void MosqQtClient::on_disconnect(int)
{
    QMetaObject::invokeMethod(this, &MosqQtClient::disconnected,
                              Qt::QueuedConnection);
}

void MosqQtClient::on_message(const mosquitto_message *msg)
{
    QByteArray topic(msg->topic);
    QByteArray payload(static_cast<const char*>(msg->payload),
                       msg->payloadlen);

    QMetaObject::invokeMethod(this,
        [this, topic, payload]()
        {
            emit messageReceived(topic, payload);
        },
        Qt::QueuedConnection);
}
