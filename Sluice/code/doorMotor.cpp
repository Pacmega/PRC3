#include <unistd.h>

#include "doorMotor.h"

doorMotor::doorMotor(motorType Type)
{
	damaged = false;
	type = Type;
}

doorMotor::~doorMotor()
{
	
}

doorMotor::getType()
{
	return type;
}