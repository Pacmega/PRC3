#include <string.h>

#include "sluice.h"
#include "button.h"
// #include "levelSensor.h"
#include "networkInterface.h"
#include "trafficLight.h"
#include "cameraSystem.h"
#include "door.h"
#include "commands.h"

sluice::sluice(int port, doorType dt, motorType mt)
    :leftDoor(door(dt, left, mt))
    ,rightDoor(door(dt, right, mt))
    ,interface(networkInterface(port))
{

}

sluice::~sluice()
{

}

waterLevel sluice::getWaterLevel()
{
    char * receivedMessage = interface.sendMessage(GetWaterLevel);
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
            /*
             TODO:
             - turn on redlights 
             - close doors
             - open valves on right door to adjust water level
             */
            return 0;

        case high:
            /* 
            TODO: 
            - turn on redlights
            - close doors
            - open valves on left door to adjust water level
            */
            return 0;
        default:
            // TODO: alert user: waterlevel not equal to high or low, or unknown reply
            break;
    }
    return -1; // something went wrong
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
