#ifndef LIGHT_H_
#define LIGHT_H_

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