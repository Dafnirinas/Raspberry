#include "eventchannelinfo.h"

EventChannelInfo::EventChannelInfo()
{

}

EventChannelInfo::EventChannelInfo(CosNaming::NamingContext_var& nc)
{
    this->nc = nc;
}

CORBA::Boolean EventChannelInfo::connectToEventChannel(char* id, char* kind) {
    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup(id);
    name[0].kind = CORBA::string_dup(kind);
    try {
        obj = nc->resolve(name);
    } catch (...) {
        std::cerr << "Can't find EventChannel: " << id << std::endl;
    }
}

CORBA::Boolean EventChannelInfo::createEventChannel(char* id, char* kind) {
    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup(id);
    name[0].kind = CORBA::string_dup(kind);

    CosNaming::Name nameFactory;
    name[0].id = CORBA::string_dup("EventChannelFactory");
    name[0].kind = CORBA::string_dup("");
    obj = nc->resolve(nameFactory);
    try {
        obj = nc->resolve(nameFactory);
    } catch (...) {
        std::cerr << "Can't find EventChannelFactory"<< std::endl;
    }
    ecf = SimpleEventChannelAdmin::EventChannelFactory::_narrow(obj);
    assert(! CORBA::is_nil(ecf));

    event_channel = ecf->create_eventchannel();
    assert(! CORBA::is_nil(event_channel));

    try {
       nc->rebind (name,
             CosEventChannelAdmin::EventChannel::_duplicate (event_channel));
     }
     catch (...) {
       cerr << "Cannot register EventChannel:" << id << endl;
     }
}

CORBA::Boolean EventChannelInfo::createPushSupplier() {
    supplier_admin = event_channel->for_suppliers();
    assert (! CORBA::is_nil(supplier_admin));

    proxy_Push_consumer = new CosEventChannelAdmin::ProxyPushConsumer_var;
}
// PushSupplier конектится к PushConsumer
CORBA::Boolean EventChannelInfo::connectToPushConsumer(CosEventComm::PushConsumer_var obj) {
    (*proxy_Push_consumer) = supplier_admin->obtain_push_consumer();
    assert(! CORBA::is_nil(*proxy_Push_consumer));
    std::cout << "ProxyPushConsumer obtained" << std::endl;
}

CORBA::Boolean EventChannelInfo::createPushConsumer() {
    consumer_admin = event_channel->for_consumers();
    assert (! CORBA::is_nil(consumer_admin));

    proxy_Push_supplier = new CosEventChannelAdmin::ProxyPushSupplier_var;
}
// PushConsumer конектится к PushSupplier
CORBA::Boolean EventChannelInfo::connectToPushSupplier(CosEventComm::PushConsumer_var obj) {
    (*proxy_Push_supplier) = consumer_admin->obtain_pull_supplier();
    assert(! CORBA::is_nil(*proxy_Push_supplier));
    std::cout << "ProxyPushSupplier obtained" << std::endl;

    (*proxy_Push_supplier)->connect_push_consumer(CosEventComm::PushConsumer::_duplicate(obj));

}

CORBA::Boolean EventChannelInfo::createPullSupplier() {
    supplier_admin = event_channel->for_suppliers();
    assert (! CORBA::is_nil(supplier_admin));

        proxy_Pull_consumer = new CosEventChannelAdmin::ProxyPullConsumer_var;
}
// PullSupplier конектится к PushConsumer
CORBA::Boolean EventChannelInfo::connectToPushConsumer(CosEventComm::PushConsumer_var obj) {
    (*proxy_Pull_consumer) = supplier_admin->obtain_pull_consumer();
    assert(! CORBA::is_nil(*proxy_Pull_consumer));
    std::cout << "ProxyPullConsumer obtained" << std::endl;
}

CORBA::Boolean EventChannelInfo::createPullConsumer() {
    consumer_admin = event_channel->for_consumers();
    assert (! CORBA::is_nil(consumer_admin));

    proxy_Pull_supplier = new CosEventChannelAdmin::ProxyPullSupplier_var;
}


CORBA::Boolean EventChannelInfo::connectToPullSupplier() {
    (*proxy_Pull_supplier) = consumer_admin->obtain_pull_supplier();
    assert(! CORBA::is_nil(*proxy_Pull_supplier));
    std::cout << "ProxyPullSupplier obtained" << std::endl;
}
