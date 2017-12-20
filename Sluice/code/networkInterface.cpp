#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>

#include "networkInterface.h"

networkInterface::networkInterface(int port)
{
	sock = CreateTCPClientSocket (port);
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
	return NULL;
}

void networkInterface::sendMessage(const char message[], int size)
{
	if(send(sock, message, size, 0) >= 0)
	{
		info_s("verbose mode", message);
	}
	else
	{
		std::cout << "Error sending message \n";
	}
}