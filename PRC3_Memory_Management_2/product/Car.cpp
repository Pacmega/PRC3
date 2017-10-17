#include "Car.h"
#include <stdexcept>

Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels)
{
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

	removeAllWheels();
	wheels.clear();

	int nrWheels = (int)otherCar.getNrWheels();

	for (int i = 0; i < nrWheels; i++)
	{
		const Wheel* newWheel = (otherCar.getWheel(i));
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());
	}
}

Car& Car::operator=(const Car &otherCar)
{
	if (&otherCar == this) return *this; // Avoid changing yourself using yourself, that breaks everything

	licencePlate = otherCar.licencePlate;
	model = otherCar.model;

	removeAllWheels();
	wheels.clear();

	int nrWheels = (int)otherCar.getNrWheels();

	for (int i = 0; i < nrWheels; i++)
	{
		const Wheel* newWheel = otherCar.getWheel(i);
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());
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
	int nrWheels = getNrWheels();

	for (int i = 0; i < nrWheels; i++)
	{
		delete wheels[i];
		wheels[i] = NULL;
	}

	wheels.clear();
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
		delete wheels[index];
		wheels.erase(wheels.begin() + index);
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
	}
	else
	{
		throw std::out_of_range("Diameter of 0 or below isn't possible");
	}
}