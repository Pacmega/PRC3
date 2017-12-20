#ifndef MOTOR_H_
#define MOTOR_H_ 

enum motorType
{
	continuous,
	pulse
};

class doorMotor
{
public:
	doorMotor(motorType Type);
	~doorMotor();

	int changePower(int newPower);

private:
	int power;
	bool damaged;
	motorType type;
};

#endif