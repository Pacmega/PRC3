#ifndef DOOR_H_
#define DOOR_H_ 

#include "valveRow.h"

enum doorState
{
	doorLocked = 0,
	doorClosed = 1,
	doorOpen = 2,
	doorClosing = 3,
	doorOpening = 4,
	doorStopped = 5,
	motorDamage = 6
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