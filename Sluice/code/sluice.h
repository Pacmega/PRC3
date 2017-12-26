#ifndef SLUICE_H
#define SLUICE_H 

#include "door.h"
#include "trafficLight.h"
#include "networkInterface.h"

class sluice
{
public:
	// Note: if port 5557, doors start off as locked
	sluice(int port, doorType dt, motorType mt, bool doorsStartLocked);
	~sluice();

	int start();
	int allowEntry();
	int allowExit();

	int openDoor(doorSide side);
	int closeDoor(doorSide side);
	int stopDoor(doorSide side);

private:
	door leftDoor;
	door rightDoor;
	waterLevel wLevel;
	networkInterface interface;

	char* receivedMessage;

	waterLevel getWaterLevel();
	doorState getDoorState(doorSide side);
	

	waterLevel interpretWaterLevel(char* receivedMessage);
};

#endif