#include "Car.h"
#include <iostream>
#include <stdexcept>

Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels)
{
	std::cout << diameter << std::endl;
	std::cout << material << std::endl;
	if (diameter > 0 && nrWheels > 2)
	{
		this->model = model;

		for (int i = 0; i < nrWheels; i++)
		{
			addWheel(diameter, material);
		}
	}
	else
	{
		throw std::out_of_range("One or more values outside of valid range");
	}
}

Car::Car(const Car& otherCar)
{
	licencePlate = otherCar.licencePlate;
	model = otherCar.model;

	// removeAllWheels();
	// wheels.clear();

	for (int i = 0; i < (int)otherCar.getNrWheels(); i++)
	{
		const Wheel* newWheel = (otherCar.getWheel(i));
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());

		delete newWheel;
		newWheel = NULL;
	}
}

Car& Car::operator=(const Car &otherCar)
{
	if (&otherCar == this) return *this; // Avoid changing yourself using yourself, that breaks everything

	model = otherCar.model;

	removeAllWheels();

	for (int i = 0; i < (int)otherCar.getNrWheels(); i++)
	{
		const Wheel* newWheel = (otherCar.getWheel(i));
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());

		delete newWheel;
		newWheel = NULL;
	}

	return *this;
}

Car::~Car()
{
	removeAllWheels();
}

// Private functions

bool Car::indexInRange(int index) const
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

void Car::removeAllWheels()
{
	for (int i = 0; i < getNrWheels(); i++)
	{
		wheels.erase(wheels.begin() + i);
		wheels[i] = NULL;
		
		/* Beta
		delete wheels[index]; // Delete the wheel itself,
		wheels[index] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
		*/
	}
}


// Public functions

const std::string& Car::getModel() const
{
	return model;
}

void Car::setLicencePlate(const std::string& licence)
{
	licencePlate = licence;
}

const std::string& Car::getLicencePlate() const
{
	return licencePlate;
}

int Car::getNrWheels() const
{
	return wheels.size();
}

const Wheel* Car::getWheel(int index) const
{
	if (0 <= index && index < getNrWheels())
	{
		return wheels[index];
	}
	else
	{
		throw std::out_of_range("There is no wheel with that index");
	}
}

void Car::removeWheel(int index)
{
	if (0 <= index && index < getNrWheels())
	{
		wheels.erase(wheels.begin() + index);
		
		/* Beta
		delete wheels[index]; // Delete the wheel itself,
		wheels[index] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
		*/
	}
	else
	{
		throw std::out_of_range("Illegal index");
	}
}

void Car::addWheel(int diameter, const std::string& material)
{
	if (diameter > 0)
	{
		Wheel *newWheel = new Wheel(diameter, material);
		wheels.push_back(newWheel);

		delete newWheel;
		newWheel = NULL;
	}
	else
	{
		throw std::out_of_range("Diameter of 0 or below isn't possible");
	}
}