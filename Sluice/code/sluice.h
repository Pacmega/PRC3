#ifndef SLUICE_H
#define SLUICE_H 

#include "door.h"
#include "trafficLight.h"
#include "networkInterface.h"

class sluice
{
public:
	// Note: if port 5557, doors start off as locked
	sluice(int port);
	~sluice();

private:
	door leftDoor;
	door rightDoor;
	trafficLight left1;
	trafficLight left2;
	trafficLight right1;
	trafficLight right2;
	networkInterface interface;
};

#endif