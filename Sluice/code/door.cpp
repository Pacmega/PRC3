#include "door.h"
#include "valveRow.h"
#include "doorMotor.h"

door::door(doorType dt, side Side, motorType mt)
	: motor(doorMotor(mt))
{
	Type = dt;
	dSide = Side;
}

door::~door()
{
	
}