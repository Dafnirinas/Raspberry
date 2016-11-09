#include <iostream>
#include <eventchannelServer.h>
#include <deviceser.h>
#include <wateringsystem_impl.h>
#include <Watering.h>

int main(int argc, char *argv[])
{
    char* EventFactoryId = "EventChannelFactory";
    char* EventFactoryKind = "";
    unsigned short usbCounts = 2;
    POA_WateringSystem* wateringSystem = new WateringSystem_impl(argc, argv, EventFactoryId, EventFactoryKind, usbCounts);

// Общие Каналы и каналыдля тестов
    wateringSystem->createEventChannel("IAPushChannel","  ");
    wateringSystem->createEventChannel("IAPullChannel","  ");
    wateringSystem->createEventChannel("OAPushChannel","  ");
    wateringSystem->createEventChannel("OAPullChannel","  ");
    wateringSystem->createEventChannel("IDPushChannel","  ");
    wateringSystem->createEventChannel("IDPullChannel","  ");
    wateringSystem->createEventChannel("ODPushChannel","  ");
    wateringSystem->createEventChannel("ODPullChannel","  ");
    wateringSystem->createEventChannel("IAOffChannel","  ");
    wateringSystem->createEventChannel("OAOffChannel","  ");
    wateringSystem->createEventChannel("IDOffChannel","  ");
    wateringSystem->createEventChannel("ODOffChannel","  ");
    wateringSystem->createEventChannel("AllOffChannel","  ");
//! Общие Каналы и каналыдля тестов

    const char* portName = "/dev/ttyACM0";
    wateringSystem->addSerialPort(portName, 0);
    wateringSystem->addDevice("PressureMeter1","", 0, 3, 0);
    wateringSystem->addDevice("Servo1","", 9, 0, 0);
    wateringSystem->addDevice("WaterLevelSensor1","", 2, 2, 0);
    wateringSystem->addDevice("Led1","", 3, 1, 0);

    wateringSystem->poaManagerActivate();
    wateringSystem->ORBRun();
    wateringSystem->POADestroy();

    return 0;
}
