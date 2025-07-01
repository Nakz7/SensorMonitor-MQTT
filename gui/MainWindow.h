#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file MainWindow.h
 * \brief Tableau de bord QtWidgets
 */

#pragma once

#include <QMainWindow>
#include "../common/MosqQtClient.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLCDNumber;
class QProgressBar;
QT_END_NAMESPACE

namespace Sensor
{
namespace Gui
{
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void buildUi();
    void hookSignals();

    Mqtt::MosqQtClient m_client;

    QLabel       *m_status;
    QLCDNumber   *m_temp;
    QProgressBar *m_hum;
    QLCDNumber   *m_press;
};
} // namespace Gui
} // namespace Sensor

#endif // MAINWINDOW_H
