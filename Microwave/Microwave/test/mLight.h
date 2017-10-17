#ifndef MLIGHT_H
#define MLIGHT_H

#include <gmock/gmock.h>
#include "iLight.h"

class mLight : public iLight
{
    public:
        MOCK_METHOD0(LightOn, void());
        MOCK_METHOD0(LightOff, void());
};

#endif
