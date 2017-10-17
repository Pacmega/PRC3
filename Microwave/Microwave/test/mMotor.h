#ifndef MMOTOR_H
#define MMOTOR_H

#include <gmock/gmock.h>
#include "iMotor.h"

class mMotor : public iMotor
{
    public:
        MOCK_METHOD1(SetPower, void(int));
};

#endif
