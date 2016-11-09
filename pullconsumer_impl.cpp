#include "pullconsumer_impl.h"

PullConsumer_impl::PullConsumer_impl()
{

}

PullConsumer_impl::PullConsumer_impl(const char* devId, const char* devKind, const char* chanId, const char* chanKind, CosNaming::NamingContext_ptr nc) {

    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup(chanId);
    name[0].kind = CORBA::string_dup(chanKind);

    CORBA::Object_var obj;

    try {
        obj = nc->resolve(name);
    }
    catch (...) {
        std::cerr << "Cannot find EventChannel !" << std::endl;
    }

    CosEventChannelAdmin::EventChannel_var event_channel;
    CosEventChannelAdmin::ConsumerAdmin_var consumer_admin;
    CosEventChannelAdmin::ProxyPullSupplier_var proxy_supplier;

    event_channel = CosEventChannelAdmin::EventChannel::_narrow(obj);
    assert(! CORBA::is_nil(event_channel));
    std::cerr << "EventChannel found." << std::endl;

    consumer_admin = event_channel->for_consumers();
    assert(! CORBA::is_nil(consumer_admin));

    proxy_supplier = consumer_admin->obtain_pull_supplier();
    assert(! CORBA::is_nil(proxy_supplier));
    std::cerr << "ProxyPullSupplier obtained." << std::endl;
}

CORBA::Any *PullConsumer_impl::pullInformation() {
    return (CORBA::Any*)proxy_supplier->pull();
}
