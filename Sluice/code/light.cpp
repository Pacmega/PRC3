#include <string>

#include "light.h"

// TODO: update light ctor in class diagram

light::light(std::string Colour)
{
	colour = Colour;
	burning = false;
}

void light::turnOn()
{
	burning = true;
}

void light::turnOff()
{
	burning = false;
}