#ifndef NETWORKINTERFACE_H_
#define NETWORKINTERFACE_H_ 

#include <strings.h>

class networkInterface
{
public:
	networkInterface();
	~networkInterface();

	string receiveMessage();
	void sendMessage(string message);

private:
	int port;

	
};

#endif