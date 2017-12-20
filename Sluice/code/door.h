#ifndef DOOR_H_
#define DOOR_H_ 

#include "valveRow.h"

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

enum doorSide
{
	left,
	right
};

class door
{
public:
	door();
	~door();
	
	int openDoor();
	int closeDoor();
	int stopDoor();
	void lock();

private:
	enum doorState {};
	bool waterLevelEqual;
	bool locked;
	valveRow leftValves[3];
	valveRow rightValves[3];
};

#endif