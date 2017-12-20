#include <string>

#include "light.h"

light::light(std::string Colour)
{
	// Use the given string to set the colour 
	colour = Colour;
	burning = false;
}

light::~light()
{
	
}

void light::turnOn()
{
	burning = true;
}

void light::turnOff()
{
	burning = false;
}