#ifndef INPUTDIGITAL_H
#define INPUTDIGITAL_H
#include <deviceser.h>
#include <eventchannelinfo.h>
#include <Watering.h>

class InputDigital : virtual public Device, public EventChannelInfo,  virtual public POA_CosEventComm::PushSupplier, virtual public POA_CosEventComm::PullSupplier
{
public:
    InputDigital();
    InputDigital(std::vector<char> info);

    void disconnect_push_supplier() {; }
    void pushInfoToChannel();

    CORBA::Any* pull();
    CORBA::Any* try_pull( CORBA::Boolean_out has_event );
    void disconnect_pull_supplier() {; }
};

#endif // INPUTDIGITAL_H
