#include <QtGui/QApplication>
#include "arduinocontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArduinoControl w;
    w.show();
    
    return a.exec();
}
