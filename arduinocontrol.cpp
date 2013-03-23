#include "arduinocontrol.h"
#include "ui_arduinocontrol.h"

ArduinoControl::ArduinoControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArduinoControl)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/on"));

    arduino = new QSerialPort(this);
    // My device is found at /dev/ttyACM0, change to /dev/ttyUSB0 or whatever matches your need
    arduino->setPortName("/dev/ttyACM0");

    if(arduino->open(QIODevice::ReadWrite))
    {
        // Baud rate
        arduino->setBaudRate(QSerialPort::Baud9600);
        // 8bit mode
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        // Skipping hw/sw control
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }

    ledon = QPixmap(":/on");
    ledoff = QPixmap(":/off");

    ui->led->setPixmap(ledoff);

    // Renaming Yes/No to On/Off
    ui->control->button(QDialogButtonBox::Yes)->setText("Turn On");
    ui->control->button(QDialogButtonBox::No)->setText("Turn Off");

    connect(ui->control, SIGNAL(clicked(QAbstractButton*)), this, SLOT(onClick(QAbstractButton*)));

    // Show info on window
    QSerialPortInfo arduinoport = QSerialPortInfo::availablePorts().at(0);
    QString info = "Name: " + arduinoport.portName() + "\n"
            + "Description : " + arduinoport.description() + "\n"
            + "Identifier: " + arduinoport.productIdentifier();

    ui->deviceinfo->setText(info);
}

ArduinoControl::~ArduinoControl()
{
    delete ui;
}

void ArduinoControl::onClick(QAbstractButton *button)
{
    if(button == ui->control->button(QDialogButtonBox::Yes))
    {
        ui->led->setPixmap(ledon);
        // Write 'y'
        arduino->write("y");
    }
    else if(button == ui->control->button(QDialogButtonBox::No))
    {
        ui->led->setPixmap(ledoff);
        // Write 'n'
        arduino->write("n");
    }
    else
    {
        // Close serial port
        arduino->close();
        // Go home
        close();
    }
}
