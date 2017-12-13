#ifndef DOOR_H_
#define DOOR_H_ 

#include "valveRow.h"

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