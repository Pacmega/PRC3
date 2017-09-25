#include "Car.h"
#include <stdexcept>

Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels)
{
	if (diameter > 0 && nrWheels > 2)
	{
		model = model;
		for (int i = 0; i < nrWheels; i++)
		{
			addWheel(diameter, material);
		}
	}
}

Car::Car(const Car& otherCar)
{
	licencePlate = otherCar.licencePlate;
	model = otherCar.model;

	deleteAllWheels();

	for (int i = 0; i < (int)otherCar.wheels.size(); i++)
	{
		Wheel *newWheel = new Wheel(*(otherCar.wheels[i]));
		wheels.push_back(newWheel);
	}
}

Car& Car::operator=(const Car &otherCar)
{
	if (&otherCar == this) return *this; // Avoid changing yourself using yourself, that breaks everything

	model = otherCar.model;

	for (int i = 0; i < (int)wheels.size(); i++)
	{
		delete wheels[i];
	}

	wheels.clear();

	for (int i = 0; i < (int)otherCar.wheels.size(); i++)
	{
		Wheel *newWheel = new Wheel(*(otherCar.wheels[i]));
		wheels.push_back(newWheel);
	}

	return *this;
}

Car::~Car()
{
	deleteAllWheels();
}

// Private functions

void Car::deleteWheel(int position)
{
	delete wheels[position]; // Delete the wheel itself,
	wheels[position] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
}

bool Car::indexInRange(int index)
{
	int actualWheels = getNrWheels();

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
	for (int i = 0; i < getNrWheels(); i++)
	{
		deleteWheel(i);
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
	if (0 <= index && index < getNrWheels())
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
	if (0 <= index && index < getNrWheels())
	{
		// Should probably delete the one, then move everything after it back 1 spot to fill the hole
		// TODO
		deleteWheel(index);
	}
	else
	{
		throw std::invalid_argument("Illegal index");
	}
}

void Car::addWheel(int diameter, const std::string& material)
{
	if (diameter > 0)
	{
		Wheel newWheel = Wheel(diameter, material);
		wheels.push_back(&newWheel);
	}
}