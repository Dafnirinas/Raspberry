#ifndef WATERINGSYSTEM_IMPL_H
#define WATERINGSYSTEM_IMPL_H
#include <vector>
#include <eventchannelServer.h>
#include <deviceser.h>
#include <Watering.h>
#include <pushconsumer_impl.h>
#include <pullsupplier_impl.h>
#include <pushsupplier_impl.h>
#include <pullconsumer_impl.h>

using namespace LibSerial;

struct Device_ {
    const char *id;
    const char *kind;
    unsigned short pin;
    unsigned short type;
    unsigned short serialPort;
};

struct EventChannel_ {
    const char *id;
    const char *kind;
};

class WateringSystem_impl : virtual public POA_WateringSystem {

    // Служебная часть
    EventChannelServer* eventServer; // Инициализация Corba сервера
//    DeviceSer* deviceTemp;  // Временный объект под девайс, через него проходят обращения
//    EventChannelStrategy* eventStrategy;
    //! Служебная часть

    std::vector<Device_> devices;
    std::vector<EventChannel_> eventChannels;

    char * factoryId;      // EventChannelFactory
    char * factoryKind;    // EventChannelFactory

    SerialStream **serialPort;

public:
    WateringSystem_impl();
    WateringSystem_impl(int argc, char *argv[], char* EventChannelFactoryId, char* EventChannelFactoryKind, unsigned short usbCounts);

    CORBA::Boolean addSerialPort(const char* name, unsigned short portNumber);
    void poaManagerActivate() { eventServer->poaManagerActivate(); }
    void ORBRun() { eventServer->run(); }
    void POADestroy() {eventServer->destroy(); }

    CORBA::Boolean createEventChannel(const char* id, const char* kind);
    char * getEventChannelFactoryId() { return factoryId; }
    char * getEventChannelFactoryKind() { return factoryKind; }

    /* Информация по содержанию NamingService */
    char* getEventChannels(); //
    char * getDevices();
    /*!!! Информация по содержанию NamingService */

    CORBA::Boolean addPoint(const char* id, const char* kind); // Добавить точку в NamingService
    CORBA::Any* addDevice(const char* id, const char* kind, unsigned short pin, unsigned short type, unsigned short serialPort);
    CORBA::Any* deleteDevice(const char *id);

    CORBA::Any* connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role);

    CORBA::UShort getPortByName(const char *str);
    /* Прямые запросы к контроллеру */
    CORBA::Any* sendMsgByStrOnPort( const char* str, CORBA::UShort portNumber ); // Ok
    CORBA::Any* sendMsgForStatusRequestByName(const char *str);   // Ok
    CORBA::Any* sendMsgForSetParameterByName(const char *str, CORBA::UShort portNumber ); // Ok
    CORBA::Any* sendMsgForAllStatusOnPort(CORBA::UShort portNumber );    // Ok
    CORBA::Any* sendMsgLoadDeviceConfigOnPort(CORBA::UShort portNumber );    // Ok
    CORBA::Any* sendMsgForSaveDeviceConfigOnPort(CORBA::UShort portNumber ); // Ok
    /*!!! Прямые запросы к контроллеру */

    /* Косвенные запросы к контроллеру через EventChannel */

    /*!!! Косвенные запросы к контроллеру через EventChannel */
};

#endif // WATERINGSYSTEM_IMPL_H
