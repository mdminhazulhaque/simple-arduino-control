#ifndef ARDUINOCONTROL_H
#define ARDUINOCONTROL_H

#include <QDialog>
#include <QPixmap>
#include <QAbstractButton>
#include <QPushButton>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QDebug>

namespace Ui {
class ArduinoControl;
}

class ArduinoControl : public QDialog
{
    Q_OBJECT

public:
    explicit ArduinoControl(QWidget *parent = 0);
    ~ArduinoControl();

private slots:
    void onClick(QAbstractButton* button);

private:
    Ui::ArduinoControl *ui;
    QSerialPort *arduino;
    QPixmap ledoff, ledon;
};

#endif // ARDUINOCONTROL_H
