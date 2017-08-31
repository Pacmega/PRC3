#include <stdexcept>
#include <cstddef>
#include <string> 	
using namespace std;

#include "Car.h"

Car::Car(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, double pricePerKm)
{
	Manufacturer = manufacturer;
	Model = model;
    BuildYear = buildYear;
    LicencePlate = licencePlate;
    Kilometers = 0;
    IsAvailable = true;
    PricePerKm = pricePerKm;
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
        throw std::out_of_range("Car is currently not available.");
    }
    if (kilometers < Kilometers)
    {
        throw std::invalid_argument("Car is returned with less kilometers than it had.");
    }

    double cost = PricePerKm * (kilometers - Kilometers);
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

const std::string Car::GetManufacturer()
{
	return Manufacturer;
}

const std::string Car::GetModel()
{
	return Model;
}

const int Car::GetBuildYear()
{
	return BuildYear;
}

const std::string Car::GetLicencePlate()
{
	return LicencePlate;
}

const bool Car::GetNeedsCleaning()
{
	return NeedsCleaning;
}

const int Car::GetKilometers()
{
	return Kilometers;
}

const bool Car::GetIsAvailable()
{
	return IsAvailable;
}
