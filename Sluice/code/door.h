#ifndef DOOR_H_
#define DOOR_H_ 

#include "lib/enums.h"
#include "valveRow.h"
#include "doorMotor.h"
#include "trafficLight.h"

class door
{
public:
	door(doorType doorType, motorType motorType, bool startsLocked);
	~door();
	
	int openDoor();
	int closeDoor();
	int stopDoor();
	int lock();
	int unlock();

private:
	bool locked;
	valveRow valves[3];
	doorMotor motor;
	doorType Type;
	trafficLight lightInside;
	trafficLight lightOutside;
};

#endif