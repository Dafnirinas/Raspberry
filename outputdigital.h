#ifndef OUTPUTDIGITAL_H
#define OUTPUTDIGITAL_H
#include "device.h"

class OutputDigital : public Device
{
public:
    OutputDigital();
    OutputDigital(std::vector<char> info);
};

#endif // OUTPUTDIGITAL_H
