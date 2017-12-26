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

private:
	door leftDoor;
	door rightDoor;
	waterLevel wLevel;
	networkInterface interface;

	char* receivedMessage;

	waterLevel getWaterLevel();
	doorState getDoorState(doorSide side);

	waterLevel interpretWaterLevel(char* receivedMessage);

	int openDoor(doorSide side);
	int closeDoor(doorSide side);
	int stopDoor(doorSide side);

	int openValve(doorSide side, int valveRow);
	int closeValve(doorSide side, int valveRow);
	int closeAllValves(doorSide side); // Valves don't break when taking unneccesary inputs (in sim), so let's close them all at once
};

#endif