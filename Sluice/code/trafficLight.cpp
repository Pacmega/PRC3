#include <string>

#include "trafficLight.h"
#include "light.h"

trafficLight::trafficLight()
{
	std::string test = "test";
	// New lights are created, passing the
	// colour as a string
	light lightRed = light(test);
	light lightGreen = light(test);
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