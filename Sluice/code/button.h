#ifndef BUTTON_H_
#define BUTTON_H_ 

#include <string>

class button
{
public:
	button();
	~button();

	bool buttonPressed();
	
private:
	std::string name;
};

#endif