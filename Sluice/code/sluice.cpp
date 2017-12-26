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

int sluice::openDoor(doorSide side)
{
    /* 
        TO DO:
        - Check doorType
        - open door
    */
    return 0;
}

int sluice::closeDoor(doorSide side)
{
    /* 
        TO DO:
        - Check doorType
        - close door
    */
    return 0;
}

int sluice::stopDoor(doorSide side)
{
    /* 
        TO DO:
        - Check doorType
        - stop door
    */
    return 0;
}

int sluice::openValve(doorSide side, int valveRow)
{
    /* 
        TO DO:
        - check if ValveRow is underwater
        - open ValveRow
        - Note: 
    */
    return 0;
}

int sluice::closeValve(doorSide side, int valveRow)
{
/* 
        TO DO:
        - Doesn't need any checks right?
        - close the valves of the door
    */
    return 0;
}

int sluice::closeAllValves()
{
/* 
        TO DO:
        - Just close all valves of all doors?
    */
    return 0;
}

int sluice::start()
{
    switch(getWaterLevel()) // check the current waterlevel
    {
        case low:
        leftDoor.outerLightRed();

        doorState leftDoor = getDoorState(left);
        if (leftDoor == doorOpen)
        {
            if (closeDoor(left) != 0)
            {
                // Doors didn't close correctly
                return -1;
            }
                // Should be doorClosed now
            leftDoor = getDoorState(left); 
        }

        if (leftDoor == doorClosed)
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
        return -4;

        case high:
        rightDoor.outerLightRed();

        doorState rightDoor = getDoorState(right);
        if (rightDoor == doorOpen)
        {
            if (closeDoor(right) != 0) // Close the door if it is open
            {
                // Doors didn't close correctly
                return -1;
            }

            rightDoor = getDoorState(left); // Should be doorClosed now

            if (rightDoor == doorClosed)
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
            return -4;
        }
        
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
