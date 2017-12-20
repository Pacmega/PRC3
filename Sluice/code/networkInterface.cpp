#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>

#include "networkInterface.h"

networkInterface::networkInterface(int argc, char *argv[])
{
	parse_args (argc, argv);

	sock = CreateTCPClientSocket (argv_ip, argv_port);
}

networkInterface::~networkInterface()
{
	close(sock);
}

char* networkInterface::receiveMessage()
{
	for (int j = 0; j < RCVBUFSIZE; ++j)
	{
		echoBuffer[j] = '\0';
	}

	if (recv(sock, echoBuffer, RCVBUFSIZE, 0) >= 0)
	{
		return echoBuffer;
	}
	return '\0';
}

void networkInterface::sendMessage(char message[])
{
	if(send(sock, message, sizeof(*message), 0) >= 0)
	{
		info_s("verbose mode", message);
	}
	else
	{
		std::cout << "Error sending message \n";
	}
}