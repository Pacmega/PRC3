#ifndef VALVEROW_H_
#define VALVEROW_H_ 

#include "light.h"

class valveRow
{
public:
	valveRow();
	~valveRow();

	void open();
	void close();

private:
	bool opened;
	
	light lightRed;
	light lightGreen;
};

#endif