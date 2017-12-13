#ifndef LIGHT_H
#define LIGHT_H

#include <strings.h>

class light
{
public:

	light();
	~light();
	
	void turnOn();
	void turnOff();

private:
	string colour;
	bool burning;
};

#endif