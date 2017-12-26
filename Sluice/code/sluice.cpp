#include <string.h>
#include <iostream>

#include "sluice.h"
#include "lib/enums.h"
#include "networkInterface.h"
#include "trafficLight.h"
// #include "cameraSystem.h"
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

int sluice::start()
{
    switch(getWaterLevel()) // check the current waterlevel
    {
        case low:
            /*
             TODO:
             - turn on red light on left door's outer traffic light
             - close left door
             - open valves on right door to adjust water level
             - continue checking if water level is now high
             - close valves on right door
             - open right door
             */
            return 0;

        case high:
            /* 
             TODO: 
             - turn on red light on right door's outer traffic light
             - close right door
             - open valves on left door to adjust water level
             - continue checking if water level is now low
             - close valves on left door
             - open left door
            */
            return 0;
        default:
            // Can't start moving boat, water level isn't at a level that would allow a boat in
            return -2;
            break;
    }
    return -1; // something unexpected went wrong
}

int sluice::allowEntry()
{
    int rtnval;
    
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

                case doorClosed:
                    rtnval = openDoor(left);
                    // TODO: needs to open the door, but not completely freeze the program
                    
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
                    // break;
            }

             
             // TODO: 
             // - check if left door is fully opened
             // - if yes: enable green light outside left door
            
            return 0;
        case high:
            switch(getDoorState(right))
            {
                case doorOpen:
                    std::cout << "woop";
                    break;
                default:
                    // All other cases
                    break;

            }
            /* 
             TODO: 
             - check if right door is fully opened
             - if yes: enable green light outside right door
            */
            return 0;

        default:
            // TODO: alert user: waterlevel not equal to high or low
            break;
    }
    return -1; // something went wrong
}

int sluice::allowExit()
{
    // TODO: code this function (currently unfinished copy paste from allowEntry())
    // switch(getWaterLevel())
    // {
    //     case low:
    //         switch(getDoorState(left))
    //         {
    //             case doorOpen:
    //                 std::cout << "woop";
    //                 break;
    //             default:
    //                 // All other cases
                    
    //         }

             
    //          TODO: 
    //          - check if left door is fully opened
    //          - if yes: enable green light inside left door
            
    //         return 0;
    //     case high:
    //         /* 
    //          TODO: 
    //          - check if right door is fully opened
    //          - if yes: enable green light inside right door
    //         */
    //         return 0;
    //     default:
    //         // TODO: alert user: waterlevel not equal to high or low
    //         break;
    // }
    return -1; // something went wrong
}
