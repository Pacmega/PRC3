#ifndef LIGHT_H
#define LIGHT_H

#include <string>

class light
{
public:

	light(std::string Colour);
	~light();
	
	void turnOn();
	void turnOff();

private:
	std::string colour;
	bool burning;
};

#endif