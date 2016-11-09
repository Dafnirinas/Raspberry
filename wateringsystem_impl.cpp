#include "wateringsystem_impl.h"

WateringSystem_impl::WateringSystem_impl()
{

}

WateringSystem_impl::WateringSystem_impl(int argc, char *argv[], char* EventChannelFactoryId, char* EventChannelFactoryKind, unsigned short usbCounts) {
    eventServer = new EventChannelServer(argc, argv);
    eventServer->resolveEventChannelFactory(EventChannelFactoryId, EventChannelFactoryKind);
    factoryId = EventChannelFactoryId;
    factoryKind = EventChannelFactoryKind;
    serialPort = new SerialStream*[usbCounts];
}

CORBA::Boolean WateringSystem_impl::addSerialPort(const char *name, unsigned short portNumber) {
    serialPort[portNumber] = new SerialStream();
//    (*serialStream1).Open("/dev/ttyACM0");
    (serialPort[portNumber])->Open(name);
    (serialPort[portNumber])->SetBaudRate(SerialStreamBuf::BAUD_9600);
    (serialPort[portNumber])->SetCharSize(SerialStreamBuf::CHAR_SIZE_8); // Для ATMEGA32U4 8-бит
    (serialPort[portNumber])->SetNumOfStopBits(1); // Возможно увеличить, если ATMEGA32U4 не справится
    (serialPort[portNumber])->SetParity(SerialStreamBuf::PARITY_ODD); // Проверка, чтобы количество единиц в символе было нечётным "Защита от ошибок"
    (serialPort[portNumber])->SetFlowControl(SerialStreamBuf::FLOW_CONTROL_HARD);
    return true;
}


CORBA::Boolean WateringSystem_impl::createEventChannel(const char* id, const char* kind) {
    eventServer->createEventChannel(id, kind);
    EventChannel_ channel;
    channel.id = id;
    channel.kind = kind;
    eventChannels.push_back(channel);
    return true;
}

char *WateringSystem_impl::getEventChannels() {
    unsigned int L = 0;
    for(std::vector<EventChannel_>::iterator it(eventChannels.begin()); it != eventChannels.end(); ++it ) {
        unsigned short l = 0;
        while((*(it)->id)!='\0') {
          ++l;
          ++L;
          ((it)->id)++;
        }
        ((it)->id) -= l;
        l = 0;
        while((*(it)->kind)!='\0') {
          ++l;
          ++L;
          ((it)->kind)++;
        }
        ((it)->kind) -= l;
    }

    char* channel = new char[L + eventChannels.size()];
    //-------------
    unsigned int i = 0;
    for(std::vector<EventChannel_>::iterator it(eventChannels.begin()); it != eventChannels.end(); ++it, ++i ) {
        unsigned short l = 0;
        while((*(it)->id)!='\0') {
          channel[i++] = (*((it)->id));
          ((it)->id)++;
          ++l;
        }
        ((it)->id) -= l;
        channel[i++] = ' ';
        l = 0;
        while((*(it)->kind)!='\0') {
          channel[i++] = (*((it)->kind));
          ((it)->kind)++;
          ++l;
        }
        ((it)->kind) -= l;
        channel[i++] = '&';
    }
    //-------------
    return channel;
}

char * WateringSystem_impl::getDevices() {
    unsigned int L = 0;
    for(std::vector<Device_>::iterator it(devices.begin()); it != devices.end(); ++it ) {
        unsigned short l = 0;
        while((*(it)->id)!='\0') {
          ++l;
          ++L;
          ((it)->id)++;
        }
        ((it)->id) -= l;
        l = 0;
        while((*(it)->kind)!='\0') {
          ++l;
          ++L;
          ((it)->kind)++;
        }
        ((it)->kind) -= l;
    }

    char* devicess = new char[L + devices.size()];
    //-------------
    unsigned int i = 0;
    for(std::vector<Device_>::iterator it(devices.begin()); it != devices.end(); ++it, ++i ) {
        unsigned short l = 0;
        while((*(it)->id)!='\0') {
          devicess[i++] = (*((it)->id));
          ((it)->id)++;
          ++l;
        }
        ((it)->id) -= l;
        devicess[i++] = ' ';
        l = 0;
        while((*(it)->kind)!='\0') {
          devicess[i++] = (*((it)->kind));
          ((it)->kind)++;
          ++l;
        }
        ((it)->kind) -= l;
        devicess[i++] = '&';
    }
    //-------------
    return devicess;
}

CORBA::Any* WateringSystem_impl::addDevice(const char* id, const char* kind, unsigned short pin, unsigned short type, unsigned short serialPort) {
    /* Сохранение данных о добавляемом девайсе на сервере(Далее в файл) */
    Device_ device;
    device.id = id;
    device.kind = kind;
    device.pin = pin;
    device.serialPort = serialPort;
    device.type = type;
    devices.push_back(device);
    /*!!! Сохранение данных о добавляемом девайсе на сервере without Crba */

    addPoint(id, kind); // Добавить девайс в NamingService Corba

    std::string str;
    // В зависимости от типа девайса регистрируются соответствующие каналы
    switch(type) {
    case 0 :    // InputAnalog
        str = "PushSupplier ";
        str += id;
        this->createEventChannel("IAPushChannel", str.c_str()); // Waiting better times
//        str = "PullConsumer ";
//        str += id;
//        this->createEventChannel("IAPullChannel", str.c_str());
//        str = "PushConsumer ";
//        str += id;
//        this->createEventChannel("IAOffChannel", str.c_str());
//        this->createEventChannel("AllOffChannel", str.c_str());
        break;
    case 1 :    // OutputAnalog
        str = "PushConsumer ";
//        str += id;
        this->createEventChannel("OAPushChannel", str.c_str());
        str = "PushSupplier ";
        str += id;
//        this->createEventChannel("OAPullChannel", str.c_str()); // Waiting better times
//        str = "PushConsumer ";
//        str += id;
//        this->createEventChannel("OAOffChannel", str.c_str());
//        this->createEventChannel("AllOffChannel", str.c_str());
        break;
    case 2 :    // InputDigital
        str = "PushSupplier ";
        str += id;
        this->createEventChannel("IDPushChannel",str.c_str()); // Waiting better times
//        str = "PullConsumer ";
//        str += id;
//        this->createEventChannel("IDPullChannel",str.c_str());
//        str = "PushConsumer ";
//        str += id;
//        this->createEventChannel("IDOffChannel", str.c_str());
//        this->createEventChannel("AllOffChannel", str.c_str());
        break;
    case 3 :    // OutputDigital
        str = "PushConsumer ";
        str += id;
        this->createEventChannel("ODPushChannel", str.c_str());
        str = "PullSupplier ";
        str += id;
//        this->createEventChannel("ODPullChannel", str.c_str()); // Waiting better times
//        str = "PushConsumer ";
//        str += id;
//        this->createEventChannel("ODOffChannel", str.c_str());
//        this->createEventChannel("AllOffChannel", str.c_str());
        break;
    }

    str = "+ ";
    str += id;
    str += ' ';
    str += pin;
    str += ' ';
    str += type;

    return sendMsgByStrOnPort(str.c_str(), serialPort);
}

CORBA::Any* WateringSystem_impl::deleteDevice(const char *id) {
    std::string str = "- ";
    str += id;
    return (this->sendMsgByStrOnPort(str.c_str(), this->getPortByName(id)));

}

CORBA::Boolean WateringSystem_impl::addPoint(const char* id, const char*kind) {
    CosNaming::Name devName;
    devName.length(1);
    devName[0].id = CORBA::string_dup(id);
    devName[0].kind = CORBA::string_dup(kind);

    eventServer->getNamingContext()->rebind(devName, this->_this()); // Это вопрос...
    return true;
}

CORBA::Any* WateringSystem_impl::sendMsgByStrOnPort(const char *str, CORBA::UShort portNumber) {
    *(serialPort[portNumber]) << str;
    usleep(10000);
    char *string;
    *(serialPort[portNumber]) >> string;
    CORBA::Any * any = new CORBA::Any();
    any->insert(string);
    return any;
}

CORBA::UShort WateringSystem_impl::getPortByName(const char *str) {
    unsigned short k = 0;
    bool copy;
    for(std::vector<Device_>::iterator it(devices.begin()); it != devices.end(); ++it, k++ ) {
        unsigned short l = 0;
        copy = true;
        while((*(it)->id)!='\0') {
            if((*((it)->id)) != str[l++]) {
                copy = false;
                break;
            }
            ((it)->id)++;
        }
        if (copy) break;
    }
    if (!copy) std::cerr << "Wrong name " << str << std::endl;
    return k;
}

/* Формирование строки на запрос по имени устройства*/
CORBA::Any* WateringSystem_impl::sendMsgForStatusRequestByName(const char *str){
    std::string stdstr = str;
    stdstr += ' ';
    stdstr += '?';

    return (sendMsgByStrOnPort(stdstr.c_str(), getPortByName(str)));
}

CORBA::Any* WateringSystem_impl::sendMsgForSetParameterByName(const char *str, unsigned short par) {
    std::string stdstr = str;
    stdstr += ' ';
    stdstr += par;
    return (sendMsgByStrOnPort(stdstr.c_str(), getPortByName(str)));
}

CORBA::Any* WateringSystem_impl::sendMsgForAllStatusOnPort(unsigned short portNumber) {
    return (sendMsgByStrOnPort("?", portNumber));
}

//CORBA::String_var WateringSystem_impl::sendMsgLoadDeviceConfigOnPort(unsigned short portNumber) {
CORBA::Any* WateringSystem_impl::sendMsgLoadDeviceConfigOnPort(unsigned short portNumber) {
    return (sendMsgByStrOnPort("load", portNumber));
}

CORBA::Any* WateringSystem_impl::sendMsgForSaveDeviceConfigOnPort(unsigned short portNumber) {
    return (sendMsgByStrOnPort("save", portNumber));
}

/*** PullConsumer Ok */
/*** PushConsumer not */
/*** PullSupplier not */
/*** PushSupplier not */
CORBA::Any* WateringSystem_impl::connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role ) {
    CORBA::Any* any = new CORBA::Any();
    switch(role) {
        case 0 : {
            PushSupplier_impl* pushSupplier = new PushSupplier_impl(devId, devKind, chanId, chanKind, eventServer->getNamingContext());
            delete pushSupplier;
            break;
        }
        case 1: {
            PushConsumer_impl* pushConsumer = new PushConsumer_impl(devId, devKind, chanId, chanKind, eventServer->getNamingContext());
            delete pushConsumer;
            break;
        }
        case 2  : {
            PullConsumer_impl* pullConsumer = new PullConsumer_impl(devId, devKind, chanId, chanKind, eventServer->getNamingContext());
            *any = *pullConsumer->pullInformation();
            delete pullConsumer;
            break;
        }
        case 3 : {
            PullSupplier_impl* pullSupplier = new PullSupplier_impl(devId, devKind, chanId, chanKind, eventServer->getNamingContext());
            delete pullSupplier;
            break;
        }
        }
//    CORBA::Any* anyp = new CORBA::Any_var();
    return any;
}
