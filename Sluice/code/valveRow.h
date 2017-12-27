#ifndef VALVEROW_H_
#define VALVEROW_H_ 

#include "light.h"
#include "communicationHandler.h"

class valveRow
{
public:
	valveRow(communicationHandler cHandler);
	~valveRow();

	void open();
	void close();

private:
	bool opened;
	communicationHandler handler;

	/*
	int openValve(doorSide side, int valveRow);
	int openLeftValve();
	int openRightValve(int valveRow);
	int closeValve(doorSide side, int valveRow);
	int closeAllValves(doorSide side); // Valves don't break when taking unneccesary inputs (in sim), so let's close them all at once
	*/
};

#endif