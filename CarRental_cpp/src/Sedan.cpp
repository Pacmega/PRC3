#include <stdexcept>
#include <cstddef>
#include <string>

#include "Car.h"
#include "Sedan.h"

Sedan::Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar, double pricePerKm)
 : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasTowbar = hasTowbar;
	NeedsCleaning = true;
}

void Sedan::Clean()
{
	NeedsCleaning = false;
}

const bool Sedan::GetNeedsCleaning()
{
	return NeedsCleaning;
}

const bool Sedan::GetHasTowbar()
{
	return HasTowbar;
}