/*
Commando:										Antwoord:
SetDoor[Left|Right]:[open|close|stop]			ack
GetDoor[Left|Right]								door state:
												- doorLocked
												- doorClosed
												- doorOpen
												- doorClosing
												- doorOpening
												- doorStopped
												- motorDamage
SetDoor[Left|Right]Valve[1...3]:[open|close]	ack
GetDoor[Left|Right]Valve[1...3]					[closed|open]
SetTrafficLight[1..4][Red|Green]:[on|off]		ack
GetTrafficLight[1..4][Red|Green]				[off|on]
GetWaterLevel									water level, which is:
												- low
												- belowValve2
												- aboveValve2
												- aboveValve3
												- high
SetDoorLock[Left|Right]:[on|off]				ack
GetDoorLockState[Left|Right]					[lockWorking|lockDamaged]
Voorbeelden:
je verstuurd bericht: “SetDoorLeftValve2:close;”,
 waarop je bericht “ack;” terug krijgt.
je verstuurd bericht GetTrafficLight2Green;”, 
waarop je bericht “off;” terug krijgt.
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_ 



#endif