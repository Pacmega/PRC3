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
	valveRow[3] leftValves;
	valveRow[3] rightValves;
};

#endif