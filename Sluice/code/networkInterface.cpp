#include "networkInterface.h"

networkInterface::networkInterface(int argc, char const *argv[])
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
	char echoBuffer[RCVBUFSIZE];

	if (recv(sock, echoBuffer, RCVBUFSIZE, 0) >= 0)
	{
		return echoBuffer;
	}
	return '\0';
}

void networkInterface::sendMessage(char message[], int size)
{
	if(send(sock, message, size, 0) >= 0)
	{
		info_s("verbose mode", message);
	}
	else
	{
		printf("Error sending message \n");
	}
}