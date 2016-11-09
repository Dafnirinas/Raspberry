#ifndef INPUTANALOG_H
#define INPUTANALOG_H
#include <eventchannelinfo.h>
#include <vector>
#include <deviceser.h>
#include <coss/CosNaming.h>
#include <coss/CosEventComm.h>
#include <coss/CosEventChannelAdmin.h>


class InputAnalog : virtual public Device, virtual public CosEventChannelAdmin::ProxyPushSupplier_stub
{

public:
    InputAnalog();
    InputAnalog(std::vector<char> info);

    void disconnect_push_supplier() {; }
    void pushInfoToChannel();

    CORBA::Any* pull();
    CORBA::Any* try_pull( CORBA::Boolean_out has_event );
    void disconnect_pull_supplier() {; }
};

#endif // INPUTANALOG_H
