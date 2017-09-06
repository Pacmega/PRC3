#include "Car.h"
#include "Limousine.h"

Limousine::Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar, double pricePerKm)
 : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasMinibar = hasMinibar;
	NeedsCleaning = 1;
	LastCleanedAtKm = 0;
}

double Limousine::Return(int kilometers)
{
	double price = Car::Return(kilometers);
	return price;
}

void Limousine::Clean(int kilometers)
{
	NeedsCleaning = false;
	LastCleanedAtKm = kilometers;
}

const bool Limousine::GetNeedsCleaning()
{
	return NeedsCleaning;
}

const bool Limousine::GetHasMinibar()
{
	return HasMinibar;
}