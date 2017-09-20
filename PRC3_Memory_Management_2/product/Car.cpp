#include "Car.h"

Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels)
{
	if (diameter > 0 && nrWheels > 2)
	{

	}
}

Car::~Car()
{
	
}

const std::string& Car::getModel()
{
	return model;
}

void Car::setLicencePlate(const std::string& licence)
{
	licencePlate = licence;
}

const std::string& Car::getLicencePlate()
{
	return licencePlate;
}

int Car::getNrWheels()
{
	return wheels.size();
}

const Wheel* Car::getWheel(int index)
{
	if (0 <= index && index < (int)wheels.size())
	{
		return NULL;
	}
	else
	{
		return NULL;
	}
}
