#include "networkInterface.h"
#include "lib/enums.h"

class communicationHandler
{
public:
	communicationHandler(networkInterface nI);
	~communicationHandler();

	waterLevel getWaterLevel(char* messageToSend);
	doorState getDoorState(char* messageToSend);
	bool sendMsgAck(char* messageToSend);
	
private:
	networkInterface interface;
};