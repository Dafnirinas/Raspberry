#ifndef PULLCONSUMER_IMPL_H
#define PULLCONSUMER_IMPL_H
#include <coss/CosEventComm.h>
#include <coss/CosNaming.h>
#include <coss/CosEventChannelAdmin.h>

class PullConsumer_impl : virtual public POA_CosEventComm::PullConsumer
{
    CosEventChannelAdmin::EventChannel_var event_channel;
    CosEventChannelAdmin::ConsumerAdmin_var consumer_admin;
    CosEventChannelAdmin::ProxyPullSupplier_var proxy_supplier;

public:
    PullConsumer_impl();
    PullConsumer_impl(const char* devId, const char* devKind, const char* chanId, const char* chanKind, CosNaming::NamingContext_ptr nc);

    CORBA::Any* pullInformation();

    void disconnect_pull_consumer() {;}
};

#endif // PULLCONSUMER_IMPL_H
