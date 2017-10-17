/*
 *  main.cpp
 *
 *  Created on: Sep 10, 2013
 *  Author: P. Lambooij
 */

#include <string>
#include <iostream>

#include "Person.h"
#include "Student.h"

int main()
{
    std::cout << "Some illustrations of instance variables and pointer variables\n";

    std::cout << "\nInstance variables:\n";
    {
        std::cout << "\tPerson person1: \n";
        Person person1("Sheldon", "Cooper");

        std::cout << "\tStudent person2: \n";
        Student person2("Bernadette", "Rostenkowski", 8000);

        std::cout << "\tEnd of scope, automatic clean-up of instance variables (dtor will be called).\n";
        std::cout << "Automatic clean-up is in the reverse order of creation of the variables.\n";
    }

    std::cout << "\nPointer variables:\n";
    {
        std::cout << "\tPerson *person1:\n";
        Person *person1 = new Person("Leonard", "Hofstadter");

        std::cout << "\tStudent *person2:\n";
        Student *person2 = new Student("Bernadette", "Rostenkowski", 8000);

        std::cout << "End of scope, pointers person1 and person2 are cleaned-up, but not the allocated memory!\n";
    }

    std::cout << "\nClean-up needs to be done by programmer, which we can no longer do now...\n\n";

    return 0;
}

