#include "door.h"
#include "valveRow.h"
#include "doorMotor.h"

door::door(doorType dt, motorType mt, bool startsLocked)
	: motor(doorMotor(mt))
{
	locked = startsLocked;
	Type = dt;
}

door::~door()
{
	
}