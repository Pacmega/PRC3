#include "Car.h"
#include "Limousine.h"

// TODO: implement your class methods here

Limousine::Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar)
 : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasMinibar = hasMinibar;
	NeedsCleaning = 1;
}

double Limousine::Return(int kilometers)
{
	double price = Car::Return(kilometers);
	NeedsCleaning = true;
	return price;
}

void Limousine::Clean()
{
	NeedsCleaning = false;
}