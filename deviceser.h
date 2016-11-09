#ifndef DEVICESER_H
#define DEVICESER_H

#include <coss/CosNaming.h>
//#include <coss/CosEventComm.h>
//#include <coss/CosEventChannelAdmin.h>
#include <Watering.h>
#include <vector>
#include <string>
#include <SerialStream.h>
#include <pthread.h>

using namespace LibSerial;


class DeviceSer : virtual public POA_Device
{

public:
    DeviceSer();
    /**
     * @param
     * name char*
     * pin short
     * type short
     * CosNaming::NamingContextRef nc ссылка на контекст имён
     */
    DeviceSer(const char* id, const char* kind, unsigned short pin, unsigned short type, SerialStream *serialPort, CosNaming::NamingContext_ptr nc);

    /**
    * Реализация отправки и приёма сообщения с КОМ порта
    */
    char *sendMessageByStr(const char* str);

    /**
    * Подготовка строки под запрос и sendMessageByStr
    */
    char *sendLineForStatusRequest();

    CORBA::Boolean addPoint(const char *id, const char *kind);

    /**
    * Действия поставщика при отсоединении от push канала
    */
    void disconnect_push_supplier();
    /**
    * Протолкнуть иформацию в канал
    */
    void pushInfoToChannel(const char& id, const char& kind);

    /**
     * Запрос к ардуино о состоянии девайса Требует таймер
     */
    CORBA::Any* pull();

    /**
     * Запрос к ардуино о состоянии девайса по условию
     */
    CORBA::Any* try_pull( CORBA::Boolean_out has_event );

    /**
     * Действия при отсоединении от pull канала
     */
    void disconnect_pull_consumer() {;}

    /**
    * Действия потребителя информации при протолкивании данных в канал
    */
    virtual void push( const CORBA::Any& data);

    /**
    * Действия потребителя при отсоединении от канала
    */
    virtual void disconnect_push_consumer();

    /**
    * Попытка забрать информацию из Pull
    */
    CORBA::Any_var tryToTakeOutPull(const char& id, const char& kind);

};

#endif // DEVICESER_H
