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

void door::outerLightGreen()
{

	lightOutside.lightRed.turnOff();
	lightOutside.lightGreen.turnOn();
}

void door::outerLightRed()
{
	lightOutside.lightGreen.turnOff();
	lightOutside.lightRed.turnOn();
}

void door::innerLightGreen()
{

	lightInside.lightRed.turnOff();
	lightInside.lightGreen.turnOn();
}

void door::innerLightRed()
{
	lightInside.lightGreen.turnOff();
	lightInside.lightRed.turnOn();
}