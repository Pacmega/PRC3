#include "trafficLight.h"
#include "light.h"

trafficLight::trafficLight()
{
	light redLight = light("red");
	light greenLight = light("green");
}

// TODO: update return value in class diagram
void trafficLight::redLight()
{
	// TODO: change name of either light redLight or function redLight
	
	redLight.turnOn();
	greenLight.turnOff();
}

// TODO: update return value in class diagram
void trafficLight::greenLight()
{
	// TODO: change name of either light greenLight or function greenLight
	
	greenLight.turnOn();
	redLight.turnOff();
}