#ifndef EVENTCHANNELINFO_H
#define EVENTCHANNELINFO_H
#include <coss/CosNaming.h>
#include <coss/CosEventComm.h>
#include <coss/CosEventChannelAdmin.h>

class EventChannelInfo
{
    CosNaming::NamingContext_var& nc;
    CORBA::Object_var obj;

    SimpleEventChannelAdmin::EventChannelFactory_var ecf;
    CosEventChannelAdmin::EventChannel_var event_channel;
    CosEventChannelAdmin::ConsumerAdmin_var consumer_admin;
    CosEventChannelAdmin::SupplierAdmin_var supplier_admin;
    CosEventChannelAdmin::ProxyPushSupplier_var *proxy_Push_supplier;
    CosEventChannelAdmin::ProxyPushConsumer_var *proxy_Push_consumer;
    CosEventChannelAdmin::ProxyPullConsumer_var *proxy_Pull_consumer;
    CosEventChannelAdmin::ProxyPullSupplier_var *proxy_Pull_supplier;


public:
    EventChannelInfo();
    EventChannelInfo(CosNaming::NamingContext_var& nc);

    CORBA::Boolean connectToEventChannel(char* id, char* kind);
    CORBA::Boolean createEventChannel(char* id, char* kind);

    CORBA::Boolean createPushSupplier();
    CORBA::Boolean connectToPushSupplier();

    CORBA::Boolean createPushConsumer();

    CORBA::Boolean createPullSupplier();
    CORBA::Boolean connectToPullSupplier();

    CORBA::Boolean createPullConsumer();

    CORBA::Any pull() { (*proxy_Pull_supplier)->pull(); }
    void push(CORBA::Any_var any) { (*proxy_Push_consumer)->push(any); }

};

#endif // EVENTCHANNELINFO_H
