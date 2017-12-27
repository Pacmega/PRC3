#ifndef VALVEROW_H_
#define VALVEROW_H_ 

#include "light.h"
#include "communicationHandler.h"
#include "lib/enums.h"

class valveRow
{
public:
	valveRow(communicationHandler cHandler, int row, doorSide side);
	~valveRow();

	bool open();
	bool close();
	bool getStatus(); // true when opened, false when closed

private:
	communicationHandler handler;

	char[] openCommand;
	char[] closeCommand;
	char[] statusCommand;
	
	char commandConstructor(int row, doorSide side);


	/*
	int openValve(doorSide side, int valveRow);
	int openLeftValve();
	int openRightValve(int valveRow);
	int closeValve(doorSide side, int valveRow);
	int closeAllValves(doorSide side); // Valves don't break when taking unneccesary inputs (in sim), so let's close them all at once
	*/
};

#endif