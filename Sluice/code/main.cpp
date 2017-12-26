#include <iostream>
#include <signal.h>

#include "sluice.h"
#include "door.h"
#include "doorMotor.h"

void ctrlCHandler(int sig){
    std::cout << "\nDit compileert blijkbaar" << std::endl;
}

int main(int argc, char const *argv[])
{
    signal (SIGINT,&ctrlCHandler);

    // Create virtual sluices for the program to save the status
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
        << "   [0]    Afsluiten\n"
        << "Ctrl+C    Noodstop\n"
        << "Ctrl+C    Herstellen (als de noodstop is ingedrukt)\n\n"
        << "Voer uw keuze in: ";
        std::cin >> line;
        choice = line[0];
        std::cout << std::endl;
        
        switch (choice)
        {
            // Sluice 1
            case '1':
                switch(normalSluice1.allowEntry())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
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
                switch(normalSluice1.allowExit())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
                break;

            // Sluice 2
            case 'q':
                switch(normalSluice2.allowEntry())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
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
                switch(normalSluice2.allowExit())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
                break;

            // Fast lock sluice
            case 'a':
                switch(fastLockSluice.allowEntry())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
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
                switch(fastLockSluice.allowExit())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
                break;

            // Pulsing motor sluice
            case 'z':
                switch(pulseMotorSluice.allowEntry())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
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
                switch(pulseMotorSluice.allowExit())
                {
                    case 0:
                        std::cout << "Invaren toegestaan. \n";
                        break;
                    case -1:
                        std::cout << "Error: waterlevel nog niet hoog genoeg om de deur te openen. \n";
                        break;
                    case -2:
                        std::cout << "Error: deur niet volledig open. Kan invaren niet toestaan. \n";
                        break;
                }
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