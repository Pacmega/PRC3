

communicationHandler::communicationHandler(networkInterface nI)
{
	interface = nI;
}

communicationHandler::~communicationHandler()
{

}

waterLevel communicationHandler::getWaterLevel(char* messageToSend)
{
    waterLevel wLevel;

    char* receivedMessage = interface.sendMessage(messageToSend)

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

doorState communicationHandler::getDoorState(char* messageToSend)
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

bool communicationHandler::sendMsgAck(char* messageToSend)
{
	bool ack = false;

	char* receivedMessage = interface.sendMessage(messageToSend);

	if (strcmp(receivedMessage, "ack") == 0)
	{
		ack = true;
	}

	return ack;
}