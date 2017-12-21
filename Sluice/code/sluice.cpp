#include <iostream>
#include "sluice.h"
#include "button.h"
//#include "levelSensor.h"
#include "networkInterface.h"
#include "trafficLight.h"
#include "cameraSystem.h"
#include "door.h"
#include "commands.h"

int findSizeOfMessage(const char message[])
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

int main(int argc, char const *argv[])
{
    // Create a network interface to communicate with the sluice at post 5556
    networkInterface Port1 = networkInterface(5555);
    networkInterface Port2 = networkInterface(5556);
    networkInterface Port3 = networkInterface(5557); // Different doors: lock it immediately after [opening|closing]
    networkInterface Port4 = networkInterface(5558); // Different motors: Only on for 1 sec (restarting a lot)

    int choice = ' ';
    char line[80];
    while (choice != 'q')
    {
        std::cout << "\n==Menu==\n"
        << "========\n"
        << "Sluis 1: \n"
        << "   [1]    Start\n"
        << "   [2]    Vrijgeven voor uitvaren\n"
        << "Sluis 2: \n"
        << "   [3]    Start\n"
        << "   [4]    Vrijgeven voor uitvaren\n"
        << "Sluis 3: \n"
        << "   [5]    Start\n"
        << "   [6]    Vrijgeven voor uitvaren\n"
        << "Sluis 4: \n"
        << "   [7]    Start\n"
        << "   [8]    Vrijgeven voor uitvaren\n\n"
        << "   [q]	  Afsluiten\n"
        << "Ctrl+C    Noodstop\n"
        << "Ctrl+C    Herstellen (als de noodstop is ingedrukt)\n\n"
        << "Voer uw keuze in: ";
        std::cin >> line;
        choice = line[0];
        std::cout << std::endl;
        
        switch (choice)
        {
        	case '1':
                std::cout << "Startknop ingedrukt. \n";
                Port1.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '2':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '3':
                std::cout << "Startknop ingedrukt. \n";
                Port2.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '4':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '5':
                std::cout << "Startknop ingedrukt. \n";
                Port3.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '6':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '7':
                std::cout << "Startknop ingedrukt. \n";
                Port4.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '8':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            default:
                std::cout << "Onjuiste keuze, probeer het opnieuw. \n";
                break;
        }
    }
    return 0;
}