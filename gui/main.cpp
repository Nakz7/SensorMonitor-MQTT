#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Sensor::Gui::MainWindow w;
    w.show();
    return app.exec();
}
