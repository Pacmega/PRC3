#ifndef DOOR_H_
#define DOOR_H_ 

#include "valveRow.h"
#include "doorMotor.h"

enum doorState
{
	doorLocked,
	doorClosed,
	doorOpen,
	doorClosing,
	doorOpening,
	doorStopped,
	doorMotorDamage
};

enum doorSide
{
	left,
	right
};

class door
{
public:
	door(doorSide side, motorType Type);
	~door();
	
	int openDoor();
	int closeDoor();
	int stopDoor();
	void lock();

private:
	bool waterLevelEqual;
	bool locked;
	doorSide side;
	valveRow leftValves[3];
	valveRow rightValves[3];
	doorMotor motor;
};

#endif