#include <iostream>
#include "sluice.h"
#include "button.h"
//#include "levelSensor.h"
#include "networkInterface.h"
#include "trafficLight.h"
#include "cameraSystem.h"
#include "door.h"

int findSizeOfMessage(char message[])
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
	int choice = ' ';
	char line[80];
	while (choice != 'q')
    {
        std::cout << "\n==Menu==\n"
             << "========\n"
             << "   [1]    Start\n"
             << "   [2]    Vrijgeven voor uitvaren\n"
             << "   [q]	   Afsluiten\n\n"
             << "Ctrl+C    Noodstop\n"
             << "Ctrl+C    Herstellen (als de noodstop is ingedrukt)\n"
             << "Voer uw keuze in: ";
        std::cin >> line;
        choice = line[0];
        std::cout << "\n";
        
        switch (choice)
        {
        	case '1':	
        	std::cout << "Startknop ingedrukt. \n";														
        	break;
        	case '2':
        	std::cout << "Vrijgeven voor uitvaren ingedrukt.\n";
        	break;
            default:
            std::cout << "Onjuiste keuze, probeer het opnieuw. \n";
            break;
        }
    }
    return 0;
}