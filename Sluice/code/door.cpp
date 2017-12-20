#include "door.h"
#include "valveRow.h"
#include "doorMotor.h"

door::door(doorSide Side, motorType Type)
	: motor(doorMotor(Type))
{
	//TODO: For waterLevelEqual, we need to check. Can't assume anything.
	
	side = Side;
}