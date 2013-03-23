Simple Arduino Control
======================

## What is it ##
I bought an Arduino Uno (Piduino) board and did some basic experiment with its MCU. I wrote a simple program to turn on/off an LED responding to serial input from host computer. Here is a GUI which opens an active connection to an Arduino port and writes serial input as user's choice.

## Requirements ##
* Qt 4/5
* QtSerialPort library
* Arduino IDE
* Arduino Uno board/other compatible boards

## How to use ##
You need to burn the sketch ```sketch.cpp``` to your MCU. Then plug it into your usb/serial port so that the application can access and write to its target port.

## Installing QtSerialPort ##
QtSerialPort is available for download at from its gitorious repository.

```
git clone git://gitorious.org/qt/qtserialport.git
```
After cloning, cd to it and build.
```
cd qtserialport
qmake
make
sudo make install
```
## Screenshots ##
After clicking ```Turn On```

![Turn On](https://github.com/minhazul-haque/simple-arduino-control/raw/master/on.png "Turn On")

And the MCU

![Arduino Turned On](https://github.com/minhazul-haque/simple-arduino-control/raw/master/camera-on.jpg "Arduino Turned On")

After clicking ```Turn Off```

![Turn Off](https://github.com/minhazul-haque/simple-arduino-control/raw/master/off.png "Turn Off")

And the MCU

![Arduino Turned Off](https://github.com/minhazul-haque/simple-arduino-control/raw/master/camera-off.jpg "Arduino Turned Off")

## Why is it so simple? ##
Because I just learned some basic serial communications between host computer and MCU. Next time I will write some complex sketches like showing text on LCD via MCU and update this application so that the text can be changed from GUI.
