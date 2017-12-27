#ifndef MOTOR_H_
#define MOTOR_H_ 

#include "lib/enums.h"

class doorMotor
{
public:
	doorMotor(motorType Type);
	~doorMotor();
	motorType getType();

private:
	bool damaged;
	motorType type;
};

#endif