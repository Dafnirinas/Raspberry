#include "inputanalog.h"

InputAnalog::InputAnalog()
{

}

/**
 * @brief InputAnalog::InputAnalog
 * @param info- "name"" ""pin"
 */
InputAnalog::InputAnalog(std::vector<char> info) {
    Device(info);
}

CORBA::Any* InputAnalog::pull() {
    // Если подошло время следующего момента для отслеживания(мониторинг влажности, тайминг датчика влажности)
    if (curTime == nextTime) {
        // Если превышен порог чувствительности
        if(limitOfSens > limit)
            try_pull(true);

    }
}

CORBA::Any* InputAnalog::try_pull( CORBA::Boolean_out has_event ) {
    // Если подошло время следующего момента для отслеживания(мониторинг влажности, тайминг датчика влажности)
    if (has_event) {
        char str[30];
        unsigned short z = 0;
        for ( std::vector<char>::iterator it = name.begin(); it != name.end(); ++it) {
            str[z++] = *it;
        }
        str[z++] = '?';
        str[z] = '\0';
    // Обрезка строки
        unsigned short i = 0;
        while (str[i] != '\0') i++;
    // !!!Обрезка строки

        return (sendReqByStr(str));
    }
}

void InputAnalog::pushInfoToChannel() {

    supplier_admin = pushEvent_channel->for_suppliers();
    assert (! CORBA::is_nil (supplier_admin));

    proxy_Push_consumer = supplier_admin->obtain_push_consumer ();
    assert (! CORBA::is_nil (proxy_Push_consumer));
    cerr << "ProxyPushConsumer obtained !" << endl;

    CORBA::Any any;
    any <<= (CORBA::Any)sendLineForStatusRequest();

    (*proxy_Push_consumer)->push(any);


}
