#include "networkInterface.h"

class communicationHandler
{
public:
	communicationHandler();
	~communicationHandler();

	waterLevel interpretWaterLevel(char* receivedMessage);
	doorState interpretDoorState(char* receivedMessage);
	doorType interpretDoorType(char* receivedMessage);
	motorType interpretMotorType(char* receivedMessage);
	bool interpretAck(char* receivedMessage);
	
};