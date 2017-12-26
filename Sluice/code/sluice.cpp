#include <string.h>
#include <iostream>

#include "sluice.h"
#include "lib/enums.h"
#include "networkInterface.h"
#include "trafficLight.h"
#include "door.h"
#include "commands.h"

sluice::sluice(int port, doorType dt, motorType mt, bool doorsStartLocked)
    :leftDoor(door(dt, mt, doorsStartLocked))
    ,rightDoor(door(dt, mt, doorsStartLocked))
    ,interface(networkInterface(port))
{

}

sluice::~sluice()
{

}

waterLevel sluice::getWaterLevel()
{
    receivedMessage = interface.sendMessage(GetWaterLevel);
    return interface.interpretWaterLevel(receivedMessage);
}

doorState sluice::getDoorState(doorSide side)
{
    if (side == left)
    {
        receivedMessage = interface.sendMessage(GetDoorLeft);
    }
    else // side has to be right
    {
        receivedMessage = interface.sendMessage(GetDoorRight);
    }
    
    return interface.interpretDoorState(receivedMessage);
}

void openOnce(doorSide side)
{

}

void openLock(doorSide side)
{

}

void openPulse(doorSide side)
{
    // TODO: 
    if (side == left)
    {
        receivedMessage = interface.sendMessage(DoorLeftOpen);
    }
    else // side has to be right
    {
        receivedMessage = interface.sendMessage(DoorRightOpen);
    }

    if (interface.interpretAck(receivedMessage))
    {
        doorState currentState = getDoorState(side);
        while (currentState != doorOpened)
        {
            if (currentState == doorStopped)
            {
                receivedMessage = interface.sendMessage(DoorLeftOpen);
                if (!interface.interpretAck)
                {
                    // If no ack was received, something is wrong
                    break;
                }
            }
            // Else the door is currently opening
        }
    }
}

void sluice::openDoor(doorSide side)
{
    // This is a thread

    /* 
        TO DO:
        - Check doorType
        - open door
    */

    // For door at port 5558: check if the state is doorStopped,
    // if so send DoorLeftOpen or DoorRightOpen again
}

void sluice::closeDoor(doorSide side)
{
    /* 
        TO DO:
        - Check doorType
        - close door
    */
}

int sluice::stopDoor(doorSide side)
{
    const char* messageToSend;

    if (side == left)
    {
        messageToSend = DoorLeftStop;
    }
    else
    {
        messageToSend = DoorRightStop;
    }

    receivedMessage = interface.sendMessage(messageToSend);
    if (interface.interpretAck(receivedMessage))
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    return -2; // Message was not acknowledged by the sim
}

int sluice::openLeftValve()
{
    // Water level can't reach beneath low and only the bottom valve can ever be opened,
    // so as long as the user is trying to open the bottom valve it's always possible.

    receivedMessage = interface.sendMessage(DoorLeftOpenBottomValve);
    if (interface.interpretAck(receivedMessage))
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    else
    {
        return -1; // Message was not acknowledged by the sim
    }
}

int sluice::openRightValve(int valveRow)
{
    const char* messageToSend;

    switch(getWaterLevel())
    {
        case low:
            if (valveRow == 1)
            {
                messageToSend = DoorRightOpenBottomValve;
            }
            else
            {
                // ValveRow is not underwater, so it can't be opened.
                return -2;
            }
            break;

        case belowValve2:
            if (valveRow == 1)
            {
                messageToSend = DoorRightOpenBottomValve;
            }
            else
            {
                // ValveRow is not underwater, so it can't be opened.
                return -2;
            }
            break;

        case aboveValve2:
            if (valveRow == 1)
            {
                messageToSend = DoorRightOpenBottomValve;
            }
            else if (valveRow == 2)
            {
                messageToSend = DoorRightOpenMiddleValve;
            }
            else
            {
                // ValveRow is not underwater, so it can't be opened.
                return -2;
            }
            break;

        case aboveValve3:
            if (valveRow == 1)
            {
                messageToSend = DoorRightOpenBottomValve;
            }
            else if (valveRow == 2)
            {
                messageToSend = DoorRightOpenMiddleValve;
            }
            else // valveRow == 3
            {
                messageToSend = DoorRightOpenTopValve;
            }
            break;

        case high:
            if (valveRow == 1)
            {
                messageToSend = DoorRightOpenBottomValve;
            }
            else if (valveRow == 2)
            {
                messageToSend = DoorRightOpenMiddleValve;
            }
            else // valveRow == 3
            {
                messageToSend = DoorRightOpenTopValve;
            }
            break;

        case waterError:
            // Invalid waterLevel
            return -1;
    }
    
    receivedMessage = interface.sendMessage(messageToSend);
    if (interface.interpretAck(receivedMessage))
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    return -2; // Message was not acknowledged by the sim
}

int sluice::openValve(doorSide side, int valveRow)
{
    int rtnval;

    if (side == left)
    {
        rtnval = openLeftValve();
    }
    else // side == right
    {
        if (valveRow < 1 || valveRow > 3)
        {
            // Invalid valveRow
            return -1;
        }

        rtnval = openRightValve(valveRow);
    }
    
    return rtnval;
}

int sluice::closeValve(doorSide side, int valveRow)
{
    if (valveRow < 1 || valveRow > 3)
    {
        // Invalid valveRow
        return -1;
    }

    const char* messageToSend;

    if(side == left)
    {
        switch(valveRow)
        {
            case 1:
                messageToSend = DoorLeftCloseBottomValve;
                break;
            case 2:
                messageToSend = DoorLeftCloseMiddleValve;
                break;
            case 3:
                messageToSend = DoorLeftCloseTopValve;
                break;
        }
    }
    else // side == right
    {
        switch(valveRow)
        {
            case 1:
                messageToSend = DoorRightCloseBottomValve;
                break;
            case 2:
                messageToSend = DoorRightCloseMiddleValve;
                break;
            case 3:
                messageToSend = DoorRightCloseTopValve;
                break;
        }
    }

    receivedMessage = interface.sendMessage(messageToSend);
    if (interface.interpretAck(receivedMessage))
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    return -2; // Message was not acknowledged by the sim
}

int sluice::closeAllValves(doorSide side)
{
    int rtnval;

    for (int i = 1; i <= 3; i++)
    {
        rtnval = closeValve(side, i);

        if (rtnval != 0)
        {
            // If one of the valves was somehow unable to close, immediately stop and return the error code.
            break;
        }
    }

    return rtnval;
}

int sluice::start()
{

    switch(getWaterLevel()) // check the current waterlevel
    {
        case low:
            leftDoor.outerLightRed();

            if (getDoorState(left) == doorOpen)
            {
                if (closeDoor(left) != 0)
                {
                    // Doors didn't close correctly
                    return -1;
                }
            }

            if (getDoorState(left) == doorClosed)
            {
                // Open the bottom valves
                for (int i = 1; i <= 3; ++i)
                {
                    openValve(right, i);
                }

                if (getWaterLevel() == high)
                {
                    if (closeAllValves(right))
                    {
                    // If the valves closed correctly, open the right door and return succes
                        openDoor(right);
                        return 0;
                    }
                    // Error closing valves
                    return -2;
                }
                // waterLevel is not high
                return -3; 
            }
            // Door isn't closed correctly
            break;

        case high:
            rightDoor.outerLightRed();

            if (getDoorState(right) == doorOpen)
            {
                if (closeDoor(right) != 0) // Close the door if it is open
                {
                    // Doors didn't close correctly
                    return -1;
                }
            }

            if (getDoorState(right) == doorClosed)
            {
                // Open the valves
                openValve(left, 1);

                if (getWaterLevel() == low)
                {
                    if (closeAllValves(left) == 0)
                    {
                        openDoor(left);
                        return 0;
                    }
                    // Valves didn't close correctly
                    return -2;
                }
                // waterLevel is not high
                return -3; 
            }
            // Door isn't closed 
            break;
        
        default:
            // Can't start moving boat, water level isn't at a level that would allow a boat in
            // return -2;
        break;
        
    }
    return -1; // something unexpected went wrong
}

int sluice::allowEntry()
{
    switch(getWaterLevel())
    {
        case low:
            switch(getDoorState(left))
            {
                case doorOpen:
                    // Door is open, so allow boats to enter
                    receivedMessage = interface.sendMessage(LeftOuterTrafficLightGreenOn);
                    if(interface.interpretAck(receivedMessage))
                    {
                        // Simulation has acknowledged command and changed the light
                        // Set the light in the virtual sluice to green as well
                        leftDoor.outerLightGreen();
                    }
                    break;

                default:
                    // All other cases: door isn't fully open, do not allow boats to enter
                    return -2;
            }
            return 0;
        
        case high:
            switch(getDoorState(right))
            {
                case doorOpen:
                    // Door is open, so allow boats to enter
                    receivedMessage = interface.sendMessage(RightOuterTrafficLightGreenOn);
                    if(interface.interpretAck(receivedMessage))
                    {
                        // Simulation has acknowledged command and changed the light
                        // Set the light in the virtual sluice to green as well
                        rightDoor.outerLightGreen();
                    }
                    break;

                default:
                    // All other cases: door isn't fully open, do not allow boats to enter
                    return -2;
            }
            return 0;

        default:
            return -1; // Waterlevel not equal to high or low
            break;
    }
}

int sluice::allowExit()
{
    switch(getWaterLevel())
    {
        case low:
            switch(getDoorState(left))
            {
                case doorOpen:
                    // Door is open, so allow boats to exit
                    receivedMessage = interface.sendMessage(LeftInnerTrafficLightGreenOn);
                    if(interface.interpretAck(receivedMessage))
                    {
                        // Simulation has acknowledged command and changed the light
                        // Set the light in the virtual sluice to green as well
                        leftDoor.innerLightGreen();
                    }
                    break;

                default:
                    // All other cases: door isn't fully open, do not allow boats to enter
                    return -2;
                    // break;
            }
            
            return 0;
        
        case high:
            switch(getDoorState(right))
            {
                case doorOpen:
                    // Door is open, so allow boats to exit
                    receivedMessage = interface.sendMessage(RightInnerTrafficLightGreenOn);
                    if(interface.interpretAck(receivedMessage))
                    {
                        // Simulation has acknowledged command and changed the light
                        // Set the light in the virtual sluice to green as well
                        rightDoor.innerLightGreen();
                    }
                    break;

                default:
                    // All other cases: door isn't fully open, do not allow boats to enter
                    return -2;
            }

            return 0;

        default:
            return -1; // Waterlevel not equal to high or low
            break;
    }
}
