#include "door.h"
#include "valveRow.h"
#include "doorMotor.h"

door::door(doorType dt, doorSide ds, motorType mt, bool startsLocked, communicationHandler Handler)
	: motor(doorMotor(mt))
{
	locked = startsLocked;
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

void door::openOnce(doorSide side)
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

    if (handler.interpretAck(messageReceived))
    {
    doorState currentState = getDoorState(side);
    while (currentState != doorOpen)
    {
        currentState = getDoorState(side);
    }

    // Door has been opened
}

void door::openLock(doorSide side)
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
    if (handler.interpretAck(messageReceived))
    {
        openOnce(side);
        // TODO: change the locally saved door as well
    }
}

void door::openPulse(doorSide side)
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

void door::openDoor(doorSide side)
{
    // TODO: Does this cause a blockage somewhere near its call?

    // Note: this is a thread

    /* 
        TO DO:
        - Check if door isn't open already
        - Check doorType
        - Open door
    */

    // For door at port 5558: check if the state is doorStopped,
    // if so send DoorLeftOpen or DoorRightOpen again
}

void door::closeDoor(doorSide side)
{
    // TODO: Does this cause a blockage somewhere near its call?

    // Note: this is a thread

    /* 
        TO DO:
        - Check doorType
        - close door
    */
}

int door::stopDoor(doorSide side)
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
    if (handler.interpretAck(messageReceived))
    {
        // Message was correctly acknowledged by the sim
        return 0;
    }
    return -2; // Message was not acknowledged by the sim
}