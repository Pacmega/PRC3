#include "valveRow.h"

valveRow::valveRow(communicationHandler cHandler, int row, doorSide side)
{
	commandConstructor(row, side);
	handler = cHandler;
	opened = false;
}

valveRow::~valveRow()
{
	
}

bool valveRow::open()
{
	return handler.interpretAck(openCommand);
}

bool valveRow::close()
{
	return handler.interpretAck(closeCommand);
}

bool valveRow::getStatus()
{
	return handler.interpretAck(statusCommand);
}

void commandConstructor(int row, doorSide side)
{
	char [] Side;
	switch(side)
	{
		case left:
			Side = "Left";
			break;
		case right:
			Side = "Right"
			break;
	}
	openCommand = "SetDoor" + Side + "Valve" + row ":open;\0"
	closeCommand =  "SetDoor" + Side + "Valve" + row ":close;\0"
	statusCommand = "GetDoor" + Side + "Valve" + row + ";\0";
}