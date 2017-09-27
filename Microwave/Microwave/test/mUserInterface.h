#ifndef MUSERINTERFACE_H
#define MUSERINTERFACE_H

#include <gmock/gmock.h>
#include "iUserInterface.h"

class mUserInterface : public iUserInterface
{
    public:
        MOCK_CONST_METHOD0(Ping, void());
        MOCK_CONST_METHOD0(GetRequestedPower, int());
        MOCK_METHOD0(StartClock, void());
        MOCK_METHOD0(StopClock, void());
};

#endif
