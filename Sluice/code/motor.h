#ifndef MOTOR_H_
#define MOTOR_H_ 

class motor
{
public:
	motor();
	~motor();

	int changePower(int newPower);

private:
	int power;
	bool damaged;
	motorType type;
};

#endif