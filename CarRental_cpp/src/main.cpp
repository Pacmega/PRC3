//============================================================================
// Name        : menu.cpp
// Author      : Freddy Hurkmans
// Version     :
// Copyright   : copyright Freddy Hurkmans
// Description : Assignment 1 example
//============================================================================

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "RentalAdministration.h"
#include "Limousine.h"
#include "Sedan.h"

void addTestDataToAdministration(RentalAdministration* administration)
{
    string licencePlates[] = {"SD-001", "SD-002", "SD-003", "SD-004", "LM-001", "LM-002"};

    for (int i = 0; i < 4; i++)
    {
        Car* sedan = new Sedan("BMW", "535d", 2012 + i, licencePlates[i], false);
        administration->Add(sedan);
    }
    for (int i = 4; i < 6; i++)
    {
        Car* limousine = new Limousine("Rolls Roys", "Phantom Extended Wheelbase", 2015, licencePlates[i], true);
        administration->Add(limousine);
    }
}

static void printCars(const RentalAdministration* administration)
{
    int CarCount = administration->Cars.size();

    for (int i = 0; i < CarCount; i++)
    {
        cout << ("Car %d: " + administration->Cars[i]->ToString() + "\n", i);
    }

}

static size_t selectCar(const RentalAdministration* administration)
{
    char choice = '\0';
    cin >> choice;
    cin.ignore();

    // if the chosen number is higher than the size of the vector, the choice will be the last item in the vector
    if (choice > administration->Cars.size())
    {
        choice = administration->Cars.size() -1; 
    }
    // if the chosen number is lower than 0, the choice will be 0
    if (choice < 0)
    {
        choice = 0;
    }
    return choice;
}

static void rentCar(RentalAdministration* administration, size_t carNumber)
{
    string plate = administration->Cars[carNumber]->GetLicencePlate();

    administration->RentCar(plate);
}

static void returnCar(RentalAdministration* administration, size_t carNumber) // <-- missing driven kilometers?
{
    string plate = administration->Cars[carNumber]->GetLicencePlate();
    // administration->ReturnCar(plate);  
}

static void printIfCarNeedsCleaning(const RentalAdministration* administration, size_t carNumber)
{
    bool needsCleaning = administration->Cars[carNumber]->GetNeedsCleaning();
    if (needsCleaning)
    {
        cout << ("This car is dirty as shit! \n");
        return;
    }
    cout << ("This car is fine! \n");
}

static void cleanCar(RentalAdministration* administration, size_t carNumber)
{
    if (administration->Cars[carNumber]->GetNeedsCleaning())
    {
        administration->Cars[carNumber]->Clean();
        cout << ("Car has been cleaned");
    }
}


static void showMenu( void )
{
    cout << ("\n\nCar Rental menu\n");
    cout << ("===============\n");
    cout << ("(1) Show all cars\n");
    cout << ("(2) Select car\n");
    cout << ("(3) Rent selected car\n");
    cout << ("(4) Return selected car\n");
    cout << ("(5) Check if car needs cleaning\n");
    cout << ("(6) Clean car\n");
    cout << ("-----------------------\n");
    cout << ("(9) QUIT\n\n");
    cout << ("Choice : ");
}

int main( void )
{
    bool quit = false;
    size_t carNumber = 0;

    RentalAdministration administration;
    addTestDataToAdministration(&administration);

    while (!quit)
    {
        char choice = '\0';
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1' :
            printCars(&administration);
            break;
        case '2' :
            carNumber = selectCar(&administration);
            break;
        case '3' :
            rentCar(&administration, carNumber);
            break;
        case '4' :
            returnCar(&administration, carNumber);
            break;
        case '5' :
            printIfCarNeedsCleaning(&administration, carNumber);
            break;
        case '6' :
            cleanCar(&administration, carNumber);
            break;

        case '9' :
            quit = true;
            break;
        default:
            cout << "\n\nI did not understand your choice (" << choice << ")" << endl;
            break;
        }
    }

    return 0;
}
