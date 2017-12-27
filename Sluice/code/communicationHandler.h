#include "networkInterface.h"
#include "lib/enums.h"

class communicationHandler
{
public:
	communicationHandler(networkInterface nI);
	~communicationHandler();

	waterLevel interpretWaterLevel(char* receivedMessage);
	doorState interpretDoorState(char* receivedMessage);
	doorType interpretDoorType(char* receivedMessage);
	motorType interpretMotorType(char* receivedMessage);
	bool sendMsgAck(char* receivedMessage);
	
private:
	networkInterface interface;
};