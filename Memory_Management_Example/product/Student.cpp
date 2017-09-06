#include <string>
#include <iostream>

#include "Student.h"

Student::Student()
{
    std::cout << "\tStudent::Student() was called\n";
}

Student::Student(std::string firstName, std::string lastName, int debt)
    : Person(firstName, lastName)
    , debt(debt)
{
    std::cout << "\tStudent::Student(" << firstName << ", " << lastName << ", " << debt << ") was called\n";
}

Student::~Student()
{
    std::cout << "\tStudent::~Student() of " << debt << " was called\n";
}
