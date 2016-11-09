#ifndef EVENTCHANNELSERVER_H
#define EVENTCHANNELSERVER_H
#include <initserver.h>
#include <coss/CosNaming.h>
#include <coss/CosEventComm.h>
#include <coss/CosEventChannelAdmin.h>

class EventChannelServer : public InitServer
{
    SimpleEventChannelAdmin::EventChannelFactory_var ecf;
//    std::vector<CosEventChannelAdmin::EventChannel_var> event_channels; // необходимости хранить данные,- нету

public:
    EventChannelServer() {}
    EventChannelServer(int argc, char *argv[]);

    ~EventChannelServer();
    CORBA::Boolean createEventChannel(const char* id, const char* kind);
    CORBA::Boolean resolveEventChannelFactory(const char* id, const char* kind);
};

#endif // EVENTCHANNELSERVER_H
