#include "deviceser.h"

DeviceSer::DeviceSer()
{
}

DeviceSer::DeviceSer(const char* id, const char* kind, unsigned short pin, unsigned short type, SerialStream *serialPort,  CosNaming::NamingContext_ptr nc) {

    this->nc = nc;
    CosNaming::Name devName;
    devName.length(1);
    devName[0].id = CORBA::string_dup(id);
    devName[0].kind = CORBA::string_dup(kind);

    nc->rebind(devName, this->_this()); // Это вопрос...

    this->name = CORBA::string_dup(id);
    this->pin = pin;
    this->type = type;
    this->serialPort = serialPort; // Ссылка на поток работы с com портом

    switch(type) {
    case 0 :    // InputAnalog
        addPoint("IAPushChannel","PushSupplier");
        addPoint("IAPullChannel","PullConsumer");
        addPoint("IAOffChannel", "PushConsumer");
        addPoint("AllOffChannel", "PushConsumer");
        break;
    case 1 :    // OutputAnalog
        addPoint("OAPushChannel","PushConsumer");
        addPoint("OAPullChannel","PullSupplier");
        addPoint("OAOffChannel", "PushConsumer");
        addPoint("AllOffChannel", "PushConsumer");
        break;
    case 2 :    // InputDigital
        addPoint("IDPushChannel","PushSupplier");
        addPoint("IDPullChannel","PullConsumer");
        addPoint("IDOffChannel", "PushConsumer");
        addPoint("AllOffChannel", "PushConsumer");
        break;
    case 3 :    // OutputDigital
        addPoint("ODPushChannel","PushConsumer");
        addPoint("ODPullChannel","PullSupplier");
        addPoint("ODOffChannel", "PushConsumer");
        addPoint("AllOffChannel", "PushConsumer");
        break;
    }

    //str - for arduino
    std::string str = "+ ";
    str += this->name;
    str += " ";
    str += this->pin;
    str += " ";
    str += this->type;

    sendMessageByStr(str.c_str());
}

DevicesStub::resolveDevice(const char& id, const char& kind)
{
    CosNaming::Name devName;
    devName.length(1);
    devName[0].id = CORBA::string_dup(id);
    devName[0].kind = CORBA::string_dup(kind);

    CORBA::Object_var obj;

    try {
        obj = nc->resolve (devName);
      }
      catch (CosNaming::NamingContext::NotFound &exc) {
        cout << "NotFound exception." << endl;
        exit (1);
      }
      catch (CosNaming::NamingContext::CannotProceed &exc) {
        cout << "CannotProceed exception." << endl;
        exit (1);
      }
      catch (CosNaming::NamingContext::InvalidName &exc) {
        cout << "InvalidName exception." << endl;
        exit (1);
      }

    Device_var newDevice = Device::_narrow(obj);
    std::pair<Device_var,CosNaming::Name> objNamePair(newDevice,devName);
    devices.push_back(objNamePair);
}


CORBA::Boolean DeviceSer::addPoint(const char *id, const char *kind)
{
    CosNaming::Name devName;
    devName.length(1);
    devName[0].id = CORBA::string_dup(id);
    devName[0].kind = CORBA::string_dup(kind);

    nc->rebind(*nextPoint, this->_this());
    return true;
}

char *DeviceSer::sendMessageByStr(const char *str) {
    *serialPort << str;
    usleep(10000);
    char *any;
    *serialPort >> any;
    return any;
}

char *DeviceSer::sendLineForStatusRequest() {
    char str[30];
    unsigned short z = 0;
    for (std::basic_string<char>::iterator it = name.begin(); it != name.end(); ++it) str[z++] = *it;
    str[z++] = ' ';
    str[z++] = '?';
    str[z++] = '\0';
    return (sendMessageByStr(str));
}

void DeviceSer::push( const CORBA::Any& data) {

}

void DeviceSer::disconnect_push_consumer() {

}
