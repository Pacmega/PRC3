#ifndef MOTOR_H_
#define MOTOR_H_ 

enum motorType
{
	continuous = 1,
	pulse = 2
};

class motor
{
public:
	motor(motorType Type);
	~motor();

	int changePower(int newPower);

private:
	int power;
	bool damaged;
	motorType type;
};

#endif