#ifndef NETWORKINTERFACE_H_
#define NETWORKINTERFACE_H_ 

#include <string>

#include "lib/Auxiliary.h"					// Used to handle arguments in the terminal
#include "lib/CreateTCPClientSocket.h"		// Used to create the TCP client socket

#define RCVBUFSIZE 32   /* Size of receive buffer */

class networkInterface
{
public:
	networkInterface(int argc, char const *argv[]);
	~networkInterface();

	char* receiveMessage();
	void sendMessage(char message[]);

private:
	// int port; <- Maybe not used since the auxiliary handles this?
	int sock; // Socket descriptor
};

#endif