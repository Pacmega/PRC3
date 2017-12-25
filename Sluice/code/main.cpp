    #include <iostream>

#include "sluice.h"
#include "door.h"
#include "doorMotor.h"

int main(int argc, char const *argv[])
{
	// Create virtual sluices for the program to save 
	sluice normalSluice1 = sluice(5555, slowLock, continuous, false);
	sluice normalSluice2 = sluice(5556, slowLock, continuous, false);
	sluice fastLockSluice = sluice(5557, fastLock, continuous, true);
	sluice pulseMotorSluice = sluice(5558, slowLock, pulse, false);
    
    int rtnval;
    int choice = ' ';
    char line[80];
    while (choice != '0')
    {
        std::cout << "\n==Menu==\n"
        << "Sluis 1: \n"
        << "   [1]    Vrijgeven voor invaren\n"
        << "   [2]    Start\n"
        << "   [3]    Vrijgeven voor uitvaren\n"
        << "Sluis 2: \n"
        << "   [q]    Vrijgeven voor invaren\n"
        << "   [w]    Start\n"
        << "   [e]    Vrijgeven voor uitvaren\n"
        << "Sluis 3: \n"
        << "   [a]    Vrijgeven voor invaren\n"
        << "   [s]    Start\n"
        << "   [d]    Vrijgeven voor uitvaren\n"
        << "Sluis 4: \n"
        << "   [z]    Vrijgeven voor invaren\n"
        << "   [x]    Start\n"
        << "   [c]    Vrijgeven voor uitvaren\n"
        << "   [0]	  Afsluiten\n"
        << "Ctrl+C    Noodstop\n"
        << "Ctrl+C    Herstellen (als de noodstop is ingedrukt)\n\n"
        << "Voer uw keuze in: ";
        std::cin >> line;
        choice = line[0];
        std::cout << std::endl;
        
        // TODO: Mate, you forgot a button. I remade the UI to fit it in,
        // 		 but the switch case needs some work for this to work again.
        switch (choice)
        {
        	// Sluice 1
        	case '1':
                std::cout << "Vrijgeven van sluis 1 voor invaren ingedrukt.\n";
                // TODO: This should actually do something
                break;
            case '2':
                std::cout << "Startknop van sluis 1 ingedrukt. \n";
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
                break;
            case '3':
                std::cout << "Vrijgeven van sluis 1 voor uitvaren ingedrukt.\n";
                // TODO: This should actually do something
                break;

            // Sluice 2
            case 'q':
                std::cout << "Vrijgeven van sluis 2 voor invaren ingedrukt.\n";
                // TODO: This should actually do something
                break;
            case 'w':
                std::cout << "Startknop van sluis 2 ingedrukt. \n";
                rtnval = normalSluice2.start();
            	if (rtnval == -1)
            	{
            		// TODO: needs a better message
            		std::cout << "Er is een onbekend probleem opgetreden." << std::endl;
            	}
            	else if (rtnval == -2)
            	{
            		std::cout << "Het waterniveau is niet laag of hoog genoeg om een boot te kunnen schutten." << std::endl;
            	}
                break;
            case 'e':
                std::cout << "Vrijgeven van sluis 2 voor uitvaren ingedrukt.\n";
                // TODO: This should actually do something
                break;

            // Fast lock sluice
            case 'a':
                std::cout << "Vrijgeven van sluis 3 voor invaren ingedrukt.\n";
                // TODO: This should actually do something
                break;
            case 's':
                std::cout << "Startknop van sluis 3 ingedrukt. \n";
                rtnval = fastLockSluice.start();
            	if (rtnval == -1)
            	{
            		// TODO: needs a better message
            		std::cout << "Er is een onbekend probleem opgetreden." << std::endl;
            	}
            	else if (rtnval == -2)
            	{
            		std::cout << "Het waterniveau is niet laag of hoog genoeg om een boot te kunnen schutten." << std::endl;
            	}
                break;
            case 'd':
                std::cout << "Vrijgeven van sluis 3 voor uitvaren ingedrukt.\n";
                // TODO: This should actually do something
                break;
            
            // Pulsing motor sluice
            case 'z':
                std::cout << "Vrijgeven van sluis 4 voor invaren ingedrukt.\n";
                // TODO: This should actually do something
                break;
            case 'x':
                std::cout << "Startknop van sluis 4 ingedrukt. \n";
                rtnval = pulseMotorSluice.start();
            	if (rtnval == -1)
            	{
            		// TODO: needs a better message
            		std::cout << "Er is een onbekend probleem opgetreden." << std::endl;
            	}
            	else if (rtnval == -2)
            	{
            		std::cout << "Het waterniveau is niet laag of hoog genoeg om een boot te kunnen schutten." << std::endl;
            	}
                break;
            case 'c':
                std::cout << "Vrijgeven van sluis 4 voor uitvaren ingedrukt.\n";
                // TODO: This should actually do something
                break;

            case '0':
                std::cout << "Afsluiten... \n";
                break;
            
            // Invalid input
            default:
                std::cout << "Onjuiste keuze, probeer het opnieuw. \n";
                break;
        }
    }
    return 0;
}