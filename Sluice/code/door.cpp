#include "door.h"
#include "valveRow.h"
#include "doorMotor.h"
#include "commands.h"
#include "communicationHandler.h"

door::door(doorType dt, doorSide ds, motorType mt, communicationHandler Handler)
	: topValves(valveRow(handler, 1, ds))
	, middleValves(valveRow(handler, 2, ds))
	, bottomValves(valveRow(handler, 3, ds))
	, motor(doorMotor(mt))
{
	type = dt;
	side = ds;
	handler = Handler;
}

door::~door()
{
	
}

void door::outerLightGreen()
{
	lightOutside.lightRed.turnOff();
	lightOutside.lightGreen.turnOn();
}

void door::outerLightRed()
{
	lightOutside.lightGreen.turnOff();
	lightOutside.lightRed.turnOn();
}

void door::innerLightGreen()
{
	lightInside.lightRed.turnOff();
	lightInside.lightGreen.turnOn();
}

void door::innerLightRed()
{
	lightInside.lightGreen.turnOff();
	lightInside.lightRed.turnOn();
}

void door::openOnce()
{
    // TODO: Does this cause a blockage somewhere near its call?
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftOpen);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightOpen);
    }

    if (messageReceived)
    {
	    doorState currentState = getDoorState(side);
	    while (currentState != doorOpen)
	    {
	        currentState = getDoorState(side);
	    }
	}

    // Door has been opened
}

void door::openLock()
{
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftUnlock);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightUnlock);
    }

    // Door should be unlocked. If the message was received correctly, open it.
    if (messageReceived)
    {
        openOnce(side);
        // TODO: change the locally saved door as well
    }
}

void door::openPulse()
{
    // TODO: Does this cause a blockage somewhere near its call?
    
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftOpen);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightOpen);
    }

    if (messageReceived)
    {
        doorState currentState = getDoorState(side);
        while (currentState != doorOpen)
        {
            if (currentState == doorStopped)
            {
                if (side == left)
                {
                    messageReceived = handler.sendMsgAck(DoorLeftOpen);
                }
                else // side == right
                {
                    messageReceived = handler.sendMsgAck(DoorRightOpen);
                }
                
                if (messageReceived)
                {
                    // If no ack was received, something is wrong
                    break;
                }
            }
            // Else the door is currently opening
        }
    }
}

void door::openDoor()
{
    // TODO: Does this cause a blockage somewhere near its call?

    // Note: this is a thread

	doorState currentState = getDoorState(side);
	if (currentState != doorOpen)
	{
		switch(type)
		{
			case noLock:
				switch(motor.getType())
				{
					case continuous:
						openOnce();
						break;
					case pulse:
						openPulse();
						break;
					case motorError:
						// Invalid engine, don't know how to open
						return;
				}
				break;

			case fastLock:
				openLock();
				break;
			case doorTypeError:
				// Invalid door type, don't know how to open
				return;
		}
	}
}

void door::closeOnce()
{
    // TODO: Does this cause a blockage somewhere near its call?
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftClose);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightClose);
    }

    if (messageReceived)
    {
	    doorState currentState = getDoorState(side);
	    while (currentState != doorOpen)
	    {
	        currentState = getDoorState(side);
	    }
	}

    // Door has been opened
}

void door::closeLock()
{
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftLock);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightLock);
    }

    // Door should be unlocked. If the message was received correctly, open it.
    if (messageReceived)
    {
        closeOnce(side);
        // TODO: change the locally saved door as well
    }
}

void door::closePulse()
{
    // TODO: Does this cause a blockage somewhere near its call?
    
    if (side == left)
    {
        messageReceived = handler.sendMsgAck(DoorLeftOpen);
    }
    else // side has to be right
    {
        messageReceived = handler.sendMsgAck(DoorRightOpen);
    }

    if (messageReceived)
    {
        doorState currentState = getDoorState(side);
        while (currentState != doorOpen)
        {
            if (currentState == doorStopped)
            {
                if (side == left)
                {
                    messageReceived = handler.sendMsgAck(DoorLeftOpen);
                }
                else // side == right
                {
                    messageReceived = handler.sendMsgAck(DoorRightOpen);
                }
                
                if (messageReceived)
                {
                    // If no ack was received, something is wrong
                    break;
                }
            }
            // Else the door is currently opening
        }
    }
}

void door::closeDoor()
{
    // TODO: Does this cause a blockage somewhere near its call?

    // Note: this is a thread

    /* 
        TO DO:
        - Check doorType
        - close door
    */
}

int door::stopDoor()
{
    const char* messageToSend;

    if (side == left)
    {
        messageToSend = DoorLeftStop;
    }
    else
    {
        messageToSend = DoorRightStop;
    }

    messageReceived = handler.sendMsgAck(messageToSend);
    if (messageReceived)
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    return -2; // Message was not acknowledged by the sim
}