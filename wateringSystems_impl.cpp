#include "wateringSystems_impl.h"

WateringSystems_impl::WateringSystems_impl()
{
}

char *WateringSystems_impl::getFlowerStates()
{
    char* stateAll = NULL;
    return stateAll;
}

char *WateringSystems_impl::getWaterLvls()
{
    char* sumAnswer = "WaterLevel is";
    for (Systems::const_iterator it(systems.begin()), end(systems.end()); it != end; ++it) {
//        Сделать запрос по всем RasberryPi на предмет отсутсвия воды в резервуарах
//        char* sendRequestByStr(const char *str);


    }
        return sumAnswer;
}

//CORBA::Boolean WateringSystems_impl::create(const char *str) {
//    systems.push_back(new WateringSystem_impl((char*)str));
//    return true;
//}

CORBA::Boolean WateringSystems_impl::setDevice(CORBA::String_var ref) {
    CORBA::Boolean res;
    return res;
}
