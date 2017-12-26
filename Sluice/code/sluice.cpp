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
    if (valveRow < 1 || valveRow > 3)
    {
        // Invalid valveRow
        return -1;
    }

    char* messageToSend;

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
    if (interpretAck(receivedMessage))
    {
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
    // switch(getWaterLevel()) // check the current waterlevel
    // {
    //     case low:
    //         leftDoor.outerLightRed();

    //         doorState leftDoor = getDoorState(left);
    //         if (leftDoor == doorOpen)
    //         {
    //             if (closeDoor(left) != 0)
    //             {
    //                 // Doors didn't close correctly
    //                 return -1;
    //             }

    //             leftDoor = getDoorState(left); // Should be doorClosed now
    //         }

    //         if (leftDoor == doorClosed)
    //         {
                
    //         }
    //         /*
    //          TODO:
    //         Check - turn on red light on left door's outer traffic light
    //         CHECK - close left door
    //          - open valves on right door to adjust water level
    //          - continue checking if water level is now high
    //          - close valves on right door
    //          - open right door
    //          */

    //         return -2;

    //     case high:
    //         rightDoor.outerLightRed();

    //         doorState rightDoor = getDoorState(right);
    //         if (rightDoor == doorOpen)
    //         {
    //             if (closeDoor(right) != 0)
    //             {
    //                 // Doors didn't close correctly
    //                 return -1;
    //             }

    //             rightDoor = getDoorState(left); // Should be doorClosed now
    //         }

    //         if (rightDoor == doorClosed)
    //         {
                
    //         }
    //         /* 
    //          TODO: 
    //         CHECK - turn on red light on right door's outer traffic light
    //         CHECK - close right door
    //          - open valves on left door to adjust water level
    //          - continue checking if water level is now low
    //          - close valves on left door
    //          - open left door
    //         */
    //         return 0;
    //     default:
    //         // Can't start moving boat, water level isn't at a level that would allow a boat in
    //         // return -2;
    //         break;
    // }
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
