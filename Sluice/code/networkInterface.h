#ifndef NETWORKINTERFACE_H_
#define NETWORKINTERFACE_H_ 

#include <string>

#include "lib/auxiliary.h"					// Used to handle arguments in the terminal
#include "lib/createTCPClientSocket.h"		// Used to create the TCP client socket
#include "lib/enums.h"

#define RCVBUFSIZE 32   /* Size of receive buffer */

class networkInterface
{
public:
	networkInterface(int port);
	~networkInterface();

	char* sendMessage(const char message[]);

	waterLevel interpretWaterLevel(char* receivedMessage);
	doorState interpretDoorState(char* receivedMessage);
	doorType interpretDoorType(char* receivedMessage);
	motorType interpretMotorType(char* receivedMessage);
	bool interpretAck(char* receivedMessage);


private:
	// int port; <- Maybe not used since the auxiliary handles this?
	int sock; // Socket descriptor
	char echoBuffer[RCVBUFSIZE];

	int sizeOfMessage(const char message[]);
	char* receiveMessage();
};

#endif