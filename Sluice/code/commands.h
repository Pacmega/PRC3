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

static const char DoorLeftOpen[] = "SetDoorLeft:open;\0";
static const char DoorLeftClose[] = "SetDoorLeft:close;\0";
static const char DoorLeftStop[] = "SetDoorLeft:stop;\0";

static const char DoorRightOpen[] = "SetDoorRight:open;\0";
static const char DoorRightClose[] = "SetDoorRight:close;\0";
static const char DoorRightStop[] = "SetDoorRight:stop;\0";

static const char GetDoorLeft[] = "GetDoorLeft;\0";
static const char GetDoorRight[] = "GetDoorRight;\0";

// Open left door valves
// TODO: replace Close Open
// TODO: replace close open
static const char DoorLeftOpenValve1[] = "SetDoorLeftValve1:open;\0";
static const char DoorLeftOpenValve2[] = "SetDoorLeftValve2:open;\0";
static const char DoorLeftOpenValve3[] = "SetDoorLeftValve3:open;\0";

// Close left door valves
static const char DoorLeftCloseValve1[] = "SetDoorLeftValve1:close;\0";
static const char DoorLeftCloseValve2[] = "SetDoorLeftValve2:close;\0";
static const char DoorLeftCloseValve3[] = "SetDoorLeftValve3:close;\0";

// Open right door valves
// TODO: replace Close Open
// TODO: replace close open
static const char DoorRightOpenValve1[] = "SetDoorRightValve1:open;\0";
static const char DoorRightOpenValve2[] = "SetDoorRightValve2:open;\0";
static const char DoorRightOpenValve3[] = "SetDoorRightValve3:open;\0";

// Close right door valves
static const char DoorRightCloseValve1[] = "SetDoorRightValve1:close;\0";
static const char DoorRightCloseValve2[] = "SetDoorRightValve2:close;\0";
static const char DoorRightCloseValve3[] = "SetDoorRightValve3:close;\0";

// Get left door valve states
static const char DoorLeftGetValve1[] = "GetDoorLeftValve1;\0";
static const char DoorLeftGetValve2[] = "GetDoorLeftValve2;\0";
static const char DoorLeftGetValve3[] = "GetDoorLeftValve3;\0";

// Get right door valve states
static const char DoorRightGetValve1[] = "GetDoorRightValve1;\0";
static const char DoorRightGetValve2[] = "GetDoorRightValve2;\0";
static const char DoorRightGetValve3[] = "GetDoorRightValve3;\0";

// Enable red traffic lights
static const char TrafficLight1RedOn[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight2RedOn[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight3RedOn[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight4RedOn[] = "SetTrafficLight1Red:on;\0";

// Disable red traffic lights
static const char TrafficLight1RedOff[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight2RedOff[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight3RedOff[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight4RedOff[] = "SetTrafficLight1Red:on;\0";

// Enable green traffic lights
static const char TrafficLight1GreenOn[] = "SetTrafficLight1Green:on;\0";
static const char TrafficLight2GreenOn[] = "SetTrafficLight2Green:on;\0";
static const char TrafficLight3GreenOn[] = "SetTrafficLight3Green:on;\0";
static const char TrafficLight4GreenOn[] = "SetTrafficLight4Green:on;\0";

// Disable green traffic lights
static const char TrafficLight1GreenOff[] = "SetTrafficLight1Green:on;\0";
static const char TrafficLight2GreenOff[] = "SetTrafficLight2Green:on;\0";
static const char TrafficLight3GreenOff[] = "SetTrafficLight3Green:on;\0";
static const char TrafficLight4GreenOff[] = "SetTrafficLight4Green:on;\0";

// Get red traffic light status
static const char TrafficLight1RedStatus[] = "SetTrafficLight1Red:on;\0";
static const char TrafficLight2RedStatus[] = "SetTrafficLight2Red:on;\0";
static const char TrafficLight3RedStatus[] = "SetTrafficLight3Red:on;\0";
static const char TrafficLight4RedStatus[] = "SetTrafficLight4Red:on;\0";

// Get green traffic light status
static const char TrafficLight1GreenStatus[] = "SetTrafficLight1Green:on;\0";
static const char TrafficLight2GreenStatus[] = "SetTrafficLight2Green:on;\0";
static const char TrafficLight3GreenStatus[] = "SetTrafficLight3Green:on;\0";
static const char TrafficLight4GreenStatus[] = "SetTrafficLight4Green:on;\0";

static const char GetWaterLevel[] = "GetWaterLevel;\0";

static const char DoorLeftLock[] = "SetDoorLockLeft:on;\0";
static const char DoorLeftUnlock[] = "SetDoorLockLeft:off;\0";

static const char DoorRightLock[] = "SetDoorLockRight:on;\0";
static const char DoorRightUnlock[] = "SetDoorLockRight:off;\0";

static const char DoorLeftLockState[] = "GetDoorLockStateLeft;\0";
static const char DoorRightLockState[] = "GetDoorLockStateRight;\0";

#endif