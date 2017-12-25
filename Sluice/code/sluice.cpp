#include <string.h>
#include <iostream>

#include "sluice.h"
// #include "button.h"
// #include "levelSensor.h"
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
    return interpretWaterLevel(receivedMessage);
}

waterLevel sluice::interpretWaterLevel(char* receivedMessage)
{
    waterLevel wLevel;

    // A switch case isn't possible for strings or character arrays.
    if (strcmp(receivedMessage, "low") == 0)
    {
        wLevel = low;
    }
    else if (strcmp(receivedMessage, "belowValve2") == 0)
    {
        wLevel = belowValve2;
    }
    else if (strcmp(receivedMessage, "aboveValve2") == 0)
    {
        wLevel = aboveValve2;
    }
    else if (strcmp(receivedMessage, "aboveValve3") == 0)
    {
        wLevel = aboveValve3;
    }
    else if (strcmp(receivedMessage, "high") == 0)
    {
        wLevel = high;
    }
    else
    {
        wLevel = error;
    }

    return wLevel;
}

int sluice::start()
{
    switch(getWaterLevel()) // check the current waterlevel
    {
        case low:
            std::cout << "hmm" << std::endl;   
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

int sluice::vrijgeven()
{
    switch(getWaterLevel())
    {
        case low:
            /* 
            TODO: 
            - open left doors  
            - give greenlight
            */
            return 0;
        case high:
            /* 
            TODO: 
            - open right doors  
            - give greenlight
            */
            return 0;
        default:
            // TODO: alert user: waterlevel not equal to high or low
            break;
    }
    return -1; // something went wrong
}
