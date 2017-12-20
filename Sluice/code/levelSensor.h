#ifndef LEVELSENSOR_H_
#define LEVELSENSOR_H_ 

enum waterLevel
{
	low = 0,
	belowValve2 = 1,
	aboveValve2 = 2,
	aboveValve3 = 3,
	high = 4
};

class levelSensor
{
public:
	levelSensor();
	~levelSensor();

private:
	enum waterLevel {};
	
};

#endif