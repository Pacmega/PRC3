#ifndef DOOR_H_
#define DOOR_H_ 

#include "valveRow.h"
#include "doorMotor.h"
#include "trafficLight.h"

enum doorState
{
	doorLocked,
	doorClosed,
	doorOpen,
	doorClosing,
	doorOpening,
	doorStopped,
	motorDamage
};

enum doorType
{
	slowLock,
	fastLock // Has to be locked fast, otherwise it breaks the motor.
};

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