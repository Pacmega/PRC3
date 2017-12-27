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

private:
	bool messageReceived;

	valveRow topValves;
	valveRow middleValves;
	valveRow bottomValves;
	doorMotor motor;
	doorType type;
	doorSide side;
	trafficLight lightInside;
	trafficLight lightOutside;
	communicationHandler handler;

	void openOnce();
	void openLock();
	void openPulse();

	void closeOnce();
	void closeLock();
	void closePulse();

	void openDoor();
	void closeDoor();
	int stopDoor();
};

#endif