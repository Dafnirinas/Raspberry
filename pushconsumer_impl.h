#ifndef PUSHCONSUMER_IMPL_H
#define PUSHCONSUMER_IMPL_H
#include <coss/CosEventComm.h>
#include <coss/CosNaming.h>

class PushConsumer_impl : virtual public POA_CosEventComm::PushConsumer
{
public:
    PushConsumer_impl();
    PushConsumer_impl(const char* devId, const char* devKind, const char* chanId, const char* chanKind, CosNaming::NamingContext_ptr nc);

    virtual void push( const CORBA::Any& data);
    virtual void disconnect_push_consumer();
};

#endif // PUSHCONSUMER_IMPL_H
