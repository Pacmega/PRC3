#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>

#include "networkInterface.h"
#include "lib/enums.h"

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
		int size = sizeOfMessage(echoBuffer);
		echoBuffer[size-1] = '\0'; // Remove the semicolon at the end of the received message
		return echoBuffer;
	}
	return NULL;
}

char* networkInterface::sendMessage(const char message[])
{
	int size = sizeOfMessage(message);

	if(send(sock, message, size, 0) >= 0)
	{
		info_s("verbose mode", message);
	}
	else
	{
		std::cout << "Error sending message \n";
	}
	return receiveMessage();
}

int networkInterface::sizeOfMessage(const char message[])
{
    int sizeOfMsg = 0;
    for (int i = 0; i < RCVBUFSIZE; i++)
    {
        if (message[i] == '\0')
        {
            return sizeOfMsg;
        }
        else
        {
            sizeOfMsg++;
        }
    }

    // Message was not NULL terminated correctly, return error
    return -1;
}

waterLevel networkInterface::interpretWaterLevel(char* receivedMessage)
{
    waterLevel wLevel;

    // A switch case isn't possible for strings or character arrays.
    if (strcmp(receivedMessage, "low") == 0)
    {
        wLevel = low;
    }
    else if (strcmp(receivedMessage, "belowValve2") == 0)
    {
        wLevel = belowValve2;
    }
    else if (strcmp(receivedMessage, "aboveValve2") == 0)
    {
        wLevel = aboveValve2;
    }
    else if (strcmp(receivedMessage, "aboveValve3") == 0)
    {
        wLevel = aboveValve3;
    }
    else if (strcmp(receivedMessage, "high") == 0)
    {
        wLevel = high;
    }
    else
    {
        wLevel = waterError;
    }

    return wLevel;
}

doorState networkInterface::interpretDoorState(char* receivedMessage)
{
	doorState dState;

	// A switch case isn't possible for strings or character arrays.
	if (strcmp(receivedMessage, "doorLocked") == 0)
	{
		dState = doorLocked;
	}
	else if (strcmp(receivedMessage, "doorClosed") == 0)
	{
		dState = doorClosed;
	}
	else if (strcmp(receivedMessage, "doorOpen") == 0)
	{
		dState = doorOpen;
	}
	else if (strcmp(receivedMessage, "doorClosing") == 0)
	{
		dState = doorClosing;
	}
	else if (strcmp(receivedMessage, "doorOpening") == 0)
	{
		dState = doorOpening;
	}
	else if (strcmp(receivedMessage, "doorStopped") == 0)
	{
		dState = doorStopped;
	}
	else if (strcmp(receivedMessage, "motorDamage") == 0)
	{
		dState = motorDamage;
	}
	else
	{
		dState = doorStateError;
	}

	return dState;
}

doorType networkInterface::interpretDoorType(char* receivedMessage)
{
	doorType dType;

	// A switch case isn't possible for strings or character arrays.
	if (strcmp(receivedMessage, "slowLock") == 0)
	{
		dType = slowLock;
	}
	else if (strcmp(receivedMessage, "fastLock") == 0)
	{
		dType = fastLock;
	}
	else
	{
		dType = doorTypeError;
	}

	return dType;
}

motorType networkInterface::interpretMotorType(char* receivedMessage)
{
	motorType mType;

	// A switch case isn't possible for strings or character arrays.
	if (strcmp(receivedMessage, "continuous") == 0)
	{
		mType = continuous;
	}
	else if (strcmp(receivedMessage, "pulse") == 0)
	{
		mType = pulse;
	}
	else
	{
		mType = motorError;
	}

	return mType;
}

bool networkInterface::interpretAck(char* receivedMessage)
{
	bool ack = false;

	if (strcmp(receivedMessage, "ack") == 0)
	{
		ack = true;
	}

	return ack;
}