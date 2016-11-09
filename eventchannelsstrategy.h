#ifndef EVENTCHANNELSSTRATEGY_H
#define EVENTCHANNELSSTRATEGY_H
#include <coss/CosEventComm.h>

class EventChannelsStrategy : virtual public POA_CosEventComm::PushConsumer
{
public:
    EventChannelsStrategy();
};

#endif // EVENTCHANNELSSTRATEGY_H
