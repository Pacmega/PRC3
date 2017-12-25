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
	int release();

private:
	door leftDoor;
	door rightDoor;
	waterLevel wLevel;
	networkInterface interface;

	char* receivedMessage;

	waterLevel getWaterLevel();
	waterLevel interpretWaterLevel(char* receivedMessage);
};

#endif