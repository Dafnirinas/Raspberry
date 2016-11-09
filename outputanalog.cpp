#include "outputanalog.h"

OutputAnalog::OutputAnalog()
{

}

OutputAnalog::OutputAnalog(std::vector<char> info) {
    Device(info);
}

void OutputAnalog::push( const CORBA::Any& data) {
    sendMessageByStr();
}
