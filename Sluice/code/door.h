#ifndef DOOR_H_
#define DOOR_H_ 

#include "lib/enums.h"
#include "valveRow.h"
#include "doorMotor.h"
#include "trafficLight.h"

class door
{
public:
	door(doorType doorType, doorSide side, motorType motorType, bool startsLocked, communicationHandler Handler);
	~door();
	
	void outerLightGreen();
	void outerLightRed();
	void innerLightGreen();
	void innerLightRed();

	int openDoor();
	int closeDoor();
	int stopDoor();
	int lock();
	int unlock();

private:
	bool locked;
	bool messageReceived;

	valveRow valves[3];
	doorMotor motor;
	doorType type;
	doorSide side;
	trafficLight lightInside;
	trafficLight lightOutside;
	communicationHandler handler;

	void openOnce(doorSide side);
	void openLock(doorSide side);
	void openPulse(doorSide side);

	void openDoor(doorSide side);
	void closeDoor(doorSide side);
	int stopDoor(doorSide side);
};

#endif