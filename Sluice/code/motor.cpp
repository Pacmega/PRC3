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
			// Power > 0: open door
			// Power < 0: close door
			if ((power > 0 && newPower > 0) || (power < 0 && newPower < 0))
			{
				power = 0;
				damaged = true;
				return -1;
			}
			else
			{
				power = newPower;
				return 0;
			}
		case needsLock:
			// not sure if this is how this is supposed to work, door causes the damage this way
			power = newPower;
			return 0;
		case pulse:
			power = newPower;
			// sleep is blocking, should probably be replaced somehow
			sleep(1);
			power = 0;
			return 0;
	}

	return -1;
}