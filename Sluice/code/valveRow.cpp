#include <string.h>

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
	// std::string Side;

	// switch(side)
	// {
	// 	case left:
	// 		Side = "Left";
	// 		break;
	// 	case right:
	// 		Side = "Right"
	// 		break;
	// }

	// std::string tempOpenCommand = "SetDoor" + Side + "Valve" + row ":open;\0";
	// std::string tempCloseCommand =  "SetDoor" + Side + "Valve" + row ":close;\0";
	// std::string tempStatusCommand = "GetDoor" + Side + "Valve" + row + ";\0";

	// strcpy(openCommand, tempOpenCommand);
	// strcpy(closeCommand, tempCloseCommand);
	// strcpy(statusCommand, tempStatusCommand);
}