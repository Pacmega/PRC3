#include <iostream>
#include "Microwave.h"

Microwave::Microwave(iLight& light, iMotor& motor, iSystem& system, iUserInterface& ui)
    : currentState(STATE_STANDBY)
    , light(light)
    , motor(motor)
    , system(system)
    , ui(ui)
{
}

States Microwave::HandleStandbyState(Events ev)
{
    States result = STATE_STANDBY;

    switch (ev)
    {
        case EV_START:
            result = STATE_OPERATING;
            motor.SetPower(power);
            light.LightOn();
            break;

        case EV_OPENDOOR:
            result = STATE_STANDBY;
            light.LightOn();
            break;

        case EV_CHANGEPOWER:
            // State doesn't change
            ui.GetReqPower();
            break;

        default:
            // ignored event, nothing to do here
            break;
    }

    return result;
}

States Microwave::HandleOperatingState(Events ev)
{
    States result = STATE_OPERATING;

    switch (ev)
    {
        case EV_TIME_UP:
            result = STATE_STANDBY;
            motor.SetPower(0);
            break;

        case EV_OPENDOOR:
            motor.SetPower(0);
            ui.StopClock();
            break;

        case EV_CHANGEPOWER:
            ui.GetReqPower();
            break;

        default:
            // ignored event, nothing to do here
            break;
    }

    return result;
}

States Microwave::HandleDoorOpenState(Events ev)
{
    States result = STATE_DOOROPEN;

    switch (ev)
    {
        case EV_CLOSEDOOR:
            if (setTime > 0)
            {
                result = STATE_OPERATING;
                motor.SetPower(power);
            }
            else if (setTime == 0)
            {
                result = STATE_STANDBY;
                light.LightOff();
            }
            break;

        case EV_CHANGEPOWER:
            ui.GetReqPower();
            break;

        default:
            // ignored event, nothing to do here
            break;
    }

    return result;
}

void Microwave::HandleEvent(Events ev)
{
    switch (currentState)
    {
        case STATE_STANDBY:
            currentState = HandleStandbyState(ev);
            break;

        case STATE_OPERATING:
            currentState = HandleOperatingState(ev);
            break;

        case STATE_DOOROPEN:
            currentState = HandleDoorOpenState(ev);
            break;

        default:
            std::cerr << "ERROR: illegal/unhandled state with number: " << currentState;
            break;
    };
}
