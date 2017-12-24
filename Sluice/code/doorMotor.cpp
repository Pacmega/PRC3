#include <unistd.h>

#include "doorMotor.h"

doorMotor::doorMotor(motorType Type)
{
	power = 0;
	damaged = false;
	type = Type;
}

doorMotor::~doorMotor()
{
	
}

int doorMotor::changePower(int newPower)
{
	switch(type)
	{
		case continuous:
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
		case pulse:
			power = newPower;
			// sleep is blocking, should probably be replaced somehow
			sleep(1);
			power = 0;
			return 0;
	}

	return -1;
}