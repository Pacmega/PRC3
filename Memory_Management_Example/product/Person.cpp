#include <string>
#include <iostream>

#include "Person.h"

Person::Person()
{
    std::cout << "\tPerson::Person() was called\n";
}

Person::Person(std::string firstName, std::string lastName)
    : firstName(firstName)
    , lastName(lastName)
{
    std::cout << "\tPerson::Person(" << firstName << ", " << lastName << ") was called\n";
}

Person::~Person()
{
    std::cout << "\tPerson::~Person() of " << firstName << " " << lastName << " was called\n";
}
