#include <string>

#include "light.h"

light::light()
{
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