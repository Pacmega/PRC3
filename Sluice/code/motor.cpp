#include "motor.h"

// TODO: update constructor to add motorType
motor::motor(motorType Type)
{
	power = 0;
	damaged = false;
	type = Type;
}

// TODO: add power as parameter in open
int motor::open(int newPower)
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
	}
}