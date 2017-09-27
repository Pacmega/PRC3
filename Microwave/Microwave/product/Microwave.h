#ifndef MICROWAVE_H
#define MICROWAVE_H

#include "Events.h"
#include "States.h"
#include "iLight.h"
#include "iMotor.h"
#include "iSystem.h"
#include "iUserInterface.h"

class Microwave
{
public:
    Microwave(iLight& light, iMotor& motor, iSystem& system, iUserInterface& ui);

    void HandleEvent(Events ev);
    States HandleIdleState(Events ev);

private:
    States currentState;
    iLight& light;
    iMotor& motor;
    iSystem& system;
    iUserInterface& ui;

};

#endif
