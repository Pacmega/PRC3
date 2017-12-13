#ifndef MOTOR_H_
#define MOTOR_H_ 

enum motorType
{
	motorType1 = 1,
	motorType2 = 2
};

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