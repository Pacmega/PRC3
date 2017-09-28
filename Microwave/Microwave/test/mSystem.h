#ifndef MSYSTEM_H
#define MSYSTEM_H

#include <gmock/gmock.h>
#include "iSystem.h"

class mSystem : public iSystem
{
    public:
        MOCK_METHOD1(SetTimer, void(int));
        MOCK_METHOD0(Ping, void());
};

#endif
