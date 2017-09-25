#include "Car.h"
#include <stdexcept>

Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels)
{
	if (diameter > 0 && nrWheels > 2)
	{
		
	}
}

// TODO: Copy constructor

Car::~Car()
{
	deleteAllWheels();
}

// Private functions

void deleteWheel(int position)
{
	delete wheels[i]; // Delete the wheel itself,
	wheels[i] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
}

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

void Car::deleteAllWheels()
{
	for (int i = 0; i < wheels.size(); i++)
	{
		deleteWheel(i);
	}
}

void copyCar(const Car& otherCar)
{
	this.licencePlate = otherCar.licencePlate;
	this.model = otherCar.model;

	deleteAllWheels();

	for (int i = 0; i < otherCar.wheels.size(); i++)
	{
		Wheel *newWheel;
		newWheel = new Wheel(*(otherCar.wheels[i]));
		wheels.push_back(newWheel);
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
		return wheels[index];
	}
	else
	{
		return NULL;
	}
}

void Car::removeWheel(int index)
{
	if (0 <= index && index < (int)wheels.size())
	{
		// Should probably delete the one, then move everything after it back 1 spot to fill the hole
		// TODO
		deleteWheel(index);
	}
	else
	{
		throw std::invalid_argument("Illegal index")
	}
}

void addWheel(int diameter, const std::string& material)
{
	if (diameter > 0)
	{
		// TODO
	}
}