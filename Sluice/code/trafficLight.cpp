#include <string>

#include "trafficLight.h"
#include "light.h"

trafficLight::trafficLight()
	: lightRed(light())
	, lightGreen(light())
{
	std::string test = "test";
}

// TODO: update return value in class diagram
void trafficLight::redLight()
{
	lightRed.turnOn();
	lightGreen.turnOff();
}

// TODO: update return value in class diagram
void trafficLight::greenLight()
{
	lightGreen.turnOn();
	lightRed.turnOff();
}