#include "MainWindow.h"
#include "../common/Topics.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QProgressBar>

using namespace Sensor;

Gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_client("sensor_gui", this)
    , m_status(nullptr)
    , m_temp(nullptr)
    , m_hum(nullptr)
    , m_press(nullptr)
{
    buildUi();
    hookSignals();
}

// ------------------------------------------------------------------
void Gui::MainWindow::buildUi()
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *v   = new QVBoxLayout(central);

    m_temp  = new QLCDNumber(5, central);
    m_hum   = new QProgressBar(central);
    m_hum->setRange(0, 100);
    m_press = new QLCDNumber(6, central);
    m_status= new QLabel("⌛ Connexion…", central);

    v->addWidget(new QLabel("Température (°C)", central));
    v->addWidget(m_temp);
    v->addWidget(new QLabel("Humidité (%)", central));
    v->addWidget(m_hum);
    v->addWidget(new QLabel("Pression (hPa)", central));
    v->addWidget(m_press);
    v->addStretch();
    v->addWidget(m_status);

    setCentralWidget(central);
    resize(320, 280);
    setWindowTitle("MQTT Monitor");
}

// ------------------------------------------------------------------
void Gui::MainWindow::hookSignals()
{
    connect(&m_client, &Mqtt::MosqQtClient::connected,
            this, [this]()
    {
        m_status->setText("✅ Connecté");
    });

    connect(&m_client, &Mqtt::MosqQtClient::disconnected,
            this, [this]()
    {
        m_status->setText("❌ Hors ligne");
    });

    // Souscriptions
    m_client.subscribeTopic(Mqtt::Topics::temp);
    m_client.subscribeTopic(Mqtt::Topics::humidity);
    m_client.subscribeTopic(Mqtt::Topics::pressure);

    connect(&m_client, &Mqtt::MosqQtClient::messageReceived,
            this,
            [this](const QByteArray &topic, const QByteArray &payload)
    {
        const double v = payload.toDouble();
        if (topic == Mqtt::Topics::temp)
            m_temp->display(v);
        else if (topic == Mqtt::Topics::humidity)
            m_hum->setValue(static_cast<int>(v));
        else if (topic == Mqtt::Topics::pressure)
            m_press->display(v);
    });
}
