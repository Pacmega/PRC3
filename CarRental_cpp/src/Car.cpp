#include <stdexcept>
#include <cstddef>
#include <string> 	
using namespace std;

#include "Car.h"

// TODO: implement your class methods here

Car::Car(const string manufacturer, const string model, const int buildYear, const string licencePlate, const double pricePerKm)
{
	Manufacturer = manufacturer;
	Model = model;
    BuildYear = buildYear;
    LicencePlate = licencePlate;
    Kilometers = 0;
    IsAvailable = true;
    this.pricePerKm = pricePerKm;
}

int Car::Rent()
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
        throw new InvalidOperationException("car was not rented");
    }
    if (kilometers < Kilometers)
    {
        throw new ArgumentException("car is returned with less kilometers than it had", "kilometers");
    }

    Decimal cost = pricePerKm * (kilometers - Kilometers);
    Kilometers = kilometers;
    IsAvailable = true;
    return cost;
}

void Car::Clean()
{

}

string Car::ToString()
{
	return Manufacturer +
        " - " + Model +
        ", " + LicencePlate;
}
