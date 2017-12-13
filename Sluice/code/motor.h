#ifndef MOTOR_H_
#define MOTOR_H_ 

class motor
{
public:
	motor();
	~motor();

	int open();
	int close();
	int stop();

private:
	int power;
	bool damaged;
	
};

#endif