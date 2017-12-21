#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_ 

#include "light.h"

//TODO: shouldn't this be a struct instead?
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