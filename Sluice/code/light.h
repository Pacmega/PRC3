#ifndef LIGHT_H_
#define LIGHT_H_

#include <string>

class light
{
public:
	light();
	~light();
	
	void turnOn();
	void turnOff();

private:
	// We do not need to store the colour, it has no purpose as the lights only exist for communication purposes.
	bool burning;
};

#endif