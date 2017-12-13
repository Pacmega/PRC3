#include <string>

#include "trafficLight.h"
#include "light.h"

trafficLight::trafficLight()
{
	light lightRed = light("red");
	light lightGreen = light("green");
}

// TODO: update return value in class diagram
void trafficLight::redLight()
{
	// TODO: change name of either light redLight or function redLight
	
	lightRed.turnOn();
	lightGreen.turnOff();
}

// TODO: update return value in class diagram
void trafficLight::greenLight()
{
	// TODO: change name of either light greenLight or function greenLight
	
	lightGreen.turnOn();
	lightRed.turnOff();
}