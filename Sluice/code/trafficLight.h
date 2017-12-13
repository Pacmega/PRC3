#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_ 

#include "light.h"

class trafficLight
{
public:
	trafficLight();
	~trafficLight();

	void redLight();
	void greenLight();

private:
	light lightRed;
	light lightGreen;
	
};

#endif