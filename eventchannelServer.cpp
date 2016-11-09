#include "eventchannelServer.h"


EventChannelServer::EventChannelServer(int argc, char *argv[]):InitServer(argc,argv)
{
}


CORBA::Boolean EventChannelServer::createEventChannel(const char *id, const char *kind) {
    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup(id);
    name[0].kind = CORBA::string_dup(kind);

    CosEventChannelAdmin::EventChannel_var eventChannel = ecf->create_eventchannel();

    assert(! CORBA::is_nil(eventChannel));

    try {
       nc->rebind (name,
             CosEventChannelAdmin::EventChannel::_duplicate (eventChannel));
     }
     catch (...) {
       std::cerr << "Cannot register EventChannel:" << id << std::endl;
     }
}

CORBA::Boolean EventChannelServer::resolveEventChannelFactory(const char* id, const char* kind)
{
    CosNaming::Name nameFactory;
    nameFactory.length(1);
    nameFactory[0].id = CORBA::string_dup(id);
    nameFactory[0].kind = CORBA::string_dup(kind);
    CORBA::Object_var objFactory;
    try {
    objFactory = nc->resolve(nameFactory);
    } catch (...) {
    std::cerr << "Can't find EventChannelFactory"<< std::endl;
    }
    ecf = SimpleEventChannelAdmin::EventChannelFactory::_narrow(objFactory);
    assert(! CORBA::is_nil(ecf));
}

EventChannelServer::~EventChannelServer() {

}
