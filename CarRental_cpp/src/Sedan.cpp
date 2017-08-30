#include <stdexcept>
#include <cstddef>
#include <string>
using namespace std;

#include "Car.h"
#include "Sedan.h"

Sedan::Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar)
 : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasTowbar = hasTowbar;
	NeedsCleaning = true;
}

void Sedan::Clean()
{
	NeedsCleaning = false;
}