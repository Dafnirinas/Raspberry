#ifndef OUTPUTANALOG_H
#define OUTPUTANALOG_H
#include <eventchannelinfo.h>
#include <vector>
#include <deviceser.h>

class OutputAnalog : virtual public Device, public EventChannelInfo, public POA_CosEventComm::PullConsumer, public POA_CosEventComm::PushConsumer
{
public:
    OutputAnalog();
    OutputAnalog(std::vector<char> info);

    void disconnect_pull_consumer() {;}

    virtual void push( const CORBA::Any& data);
    virtual void disconnect_push_consumer();
};

#endif // OUTPUTANALOG_H
