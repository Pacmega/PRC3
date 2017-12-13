#ifndef NETWORKINTERFACE_H_
#define NETWORKINTERFACE_H_ 

#include <string>

class networkInterface
{
public:
	networkInterface();
	~networkInterface();

	std::string receiveMessage();
	void sendMessage(std::string message);

private:
	int port;

	
};

#endif