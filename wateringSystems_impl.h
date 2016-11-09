#ifndef WATERING_IMPL_H
#define WATERING_IMPL_H

#include <Watering.h>
#include <wateringsystem_impl.h>
#include <vector>

/**
 * @brief The WateringSystems_impl class
 * Уровень абстракции- RasberryPi
 */
class WateringSystems_impl : virtual public POA_WateringSystems
{
//    CORBA::Object_var* poaObj;
//    PortableServer::POA_var poa;

    typedef  std::vector<WateringSystem_impl*> Systems;
    Systems systems;

public:
    WateringSystems_impl();
    CORBA::Boolean setDevice(CORBA::String_var ref);

    CORBA::String_var getStatusDevice(CORBA::String_var ref);
    CORBA::String_var getStatus();

    CORBA::Boolean create(const char *str); // Создать систему полива
    char* getFlowerStates(); // Проверка состояния всех цветков
    char* getWaterLvls();

    //---------------
    //---------------
};

#endif // WATERING_IMPL_H
