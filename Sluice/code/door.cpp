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

void door::OuterLightGreen()
{

	lightOutside.lightRed.turnOff();
	lightOutside.lightGreen.turnOn();
}

void door::OuterLightRed()
{
	lightOutside.lightGreen.turnOff();
	lightOutside.lightRed.turnOn();
}

void door::InnerLightGreen()
{

	lightInside.lightRed.turnOff();
	lightInside.lightGreen.turnOn();
}

void door::InnerLightRed()
{
	lightInside.lightGreen.turnOff();
	lightInside.lightRed.turnOn();
}