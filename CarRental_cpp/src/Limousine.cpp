#include "Limousine.h"

// TODO: implement your class methods here

Limousine::Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar) : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasMinibar = hasMinibar;
	needsCleaning = False;
}

Limousine::Return(int kilometers)
{
	double price = Car::Return(kilometers);
	needsCleaning = true;
	return price;
}

Limousine::Clean()
{
	needsCleaning = False;
}