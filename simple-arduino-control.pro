QT       += core gui
TARGET = simple-arduino-control
TEMPLATE = app
CONFIG += serialport
SOURCES += main.cpp\
        arduinocontrol.cpp
HEADERS  += arduinocontrol.h
FORMS    += arduinocontrol.ui
RESOURCES += \
    ledicons.qrc
