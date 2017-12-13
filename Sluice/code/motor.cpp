#include <unistd.h>

#include "motor.h"

// TODO: update constructor to add motorType enum (singleMessage, needsLock, pulse)
motor::motor(motorType Type)
{
	power = 0;
	damaged = false;
	type = Type;
}

// TODO: change open/close to changePower()
// TODO: add newPower as parameter in open
int motor::changePower(int newPower)
{
	switch(type)
	{
		case singleMessage:
			if (power > 0)
			{
				power = 0;
				damaged = true;
			}
			else
			{
				power = newPower;
			}
			break;
		case needsLock:
			// not sure if this is how this is supposed to work, door causes the damage this way
			power = newPower;
			break;
		case pulse:
			power = newPower;
			sleep(1);
			power = 0;
			break;
	}
}

int motor::close(int newPower)
{

}