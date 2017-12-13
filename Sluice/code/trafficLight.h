#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_ 

#include "light.h"

class trafficLight
{
public:
	trafficLight();
	~trafficLight();

	int redLight();
	int greenLight();

private:
	light redLight;
	light greenLight;
	
};

#endif