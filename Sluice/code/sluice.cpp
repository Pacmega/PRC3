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
    return interface.sendMessage(GetWaterLevel);
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
            // TODO: alert user: waterlevel not equal to high or low 
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

