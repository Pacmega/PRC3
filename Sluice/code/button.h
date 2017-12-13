#ifndef BUTTON_H_
#define BUTTON_H_ 

#include <strings.h>

class button
{
public:
	button();
	~button();

	bool buttonPressed();
	
private:
	string name;
};

#endif