#include <iostream>

#include "sluice.h"
#include "door.h"
#include "doorMotor.h"

int main(int argc, char const *argv[])
{
	sluice normalSluice1 = sluice(5555, slowLock, continuous);
	sluice normalSluice2 = sluice(5556, slowLock, continuous);
	sluice fastLockSluice = sluice(5557, fastLock, continuous); // Doors start off locked
	sluice pulseMotorSluice = sluice(5558, slowLock, pulse);
    
    // Create a network interface to communicate with the sluice at post 5556
    // networkInterface Port1 = networkInterface(5555);
    // networkInterface Port2 = networkInterface(5556);
    // networkInterface Port3 = networkInterface(5557); // Different doors: lock it immediately after [opening|closing]
    // networkInterface Port4 = networkInterface(5558); // Different motors: Only on for 1 sec (restarting a lot)

	int rtnval;
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
                rtnval = normalSluice1.start();
                if (rtnval == -1)
                {
                	// TODO: needs a better message
                	std::cout << "Er is een onbekend probleem opgetreden." << std::endl;
                }
                else if (rtnval == -2)
                {
                	std::cout << "Het waterniveau is niet laag of hoog genoeg om een boot te kunnen schutten." << std::endl;
                }
                //Port1.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '2':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '3':
                std::cout << "Startknop ingedrukt. \n";
                //Port2.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '4':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '5':
                std::cout << "Startknop ingedrukt. \n";
                //Port3.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
                break;
            case '6':
                std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
                break;
            case '7':
                std::cout << "Startknop ingedrukt. \n";
                //Port4.sendMessage(TrafficLight1GreenOn, findSizeOfMessage(TrafficLight1GreenOn));
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