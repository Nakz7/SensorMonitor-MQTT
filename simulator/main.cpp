/**
 * \file main.cpp
 * \brief Simulateur de capteurs — publie toutes les 2 s
 */

#include "../common/Topics.h"
#include "../common/Utils.h"
#include "../common/MosqQtClient.h"

#include <QCoreApplication>
#include <QTimer>

using namespace Sensor;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Mqtt::MosqQtClient client("sensor_sim", &app);

    QObject::connect(&client, &Mqtt::MosqQtClient::connected, []()
    {
        qInfo("[Simulator] Connected to broker.");
    });

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&client]()
    {
        client.publishMessage(Mqtt::Topics::temp,
                              QByteArray::number(Utils::randomBetween(15, 30)));

        client.publishMessage(Mqtt::Topics::humidity,
                              QByteArray::number(Utils::randomBetween(30, 80)));

        client.publishMessage(Mqtt::Topics::pressure,
                              QByteArray::number(Utils::randomBetween(990, 1025)));
    });
    timer.start(2000);

    return app.exec();
}
