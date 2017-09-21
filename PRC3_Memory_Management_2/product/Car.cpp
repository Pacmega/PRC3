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

// Private functions

bool Car::indexInRange(int index)
{
	int actualWheels = wheels.size();

	// In the header file it is defined as a pre that a car has at least 2 wheels.
	if (index > 2 && index < actualWheels)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Public functions

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
