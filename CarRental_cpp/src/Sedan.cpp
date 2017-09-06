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
	LastCleanedAtKm = 0;
}

void Sedan::Clean(int kilometers)
{
	NeedsCleaning = false;
	LastCleanedAtKm = kilometers;
}

const bool Sedan::GetNeedsCleaning()
{
	return NeedsCleaning;
}

const bool Sedan::GetHasTowbar()
{
	return HasTowbar;
}