#ifndef SLUICE_H
#define SLUICE_H 

#include "door.h"
#include "trafficLight.h"
#include "networkInterface.h"

enum waterLevel
{
	low,
	belowValve2,
	aboveValve2,
	aboveValve3,
	high
};

class sluice
{
public:
	// Note: if port 5557, doors start off as locked
	sluice(int port, doorType dt, motorType mt);
	~sluice();

	int start();
	int vrijgeven();
private:
	door leftDoor;
	door rightDoor;
	waterLevel wLevel;

	networkInterface interface;

	waterLevel getWaterLevel();
};

#endif