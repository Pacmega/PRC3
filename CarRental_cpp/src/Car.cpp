#include <stdexcept>
#include <cstddef>
#include <string> 	
using namespace std;

#include "Car.h"

Car(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, double pricePerKm)
{
	Manufacturer = manufacturer;
	Model = model;
    BuildYear = buildYear;
    LicencePlate = licencePlate;
    Kilometers = 0;
    IsAvailable = true;
    this.pricePerKm = pricePerKm;
    NeedsCleaning = false; // New cars don't need cleaning.
}

bool Car::Rent()
{
    if (!IsAvailable)
    {
        return false;
    }

    IsAvailable = false;
    return true;
}

double Car::Return(int kilometers)
{
    if (IsAvailable)
    {
        throw std::out_of_range("car was not rented");
    }
    if (kilometers < Kilometers)
    {
        throw std::invalid_argument("car is returned with less kilometers than it had");
    }

    double cost = pricePerKm * (kilometers - Kilometers);
    Kilometers = kilometers;
    IsAvailable = true;
    return cost;
}

const std::string Car::ToString()
{
	return Manufacturer +
        " - " + Model +
        ", " + LicencePlate;
}
