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
}

Car::Car(const Car& otherCar)
{
	licencePlate = otherCar.licencePlate;
	model = otherCar.model;

	removeAllWheels();

	for (int i = 0; i < (int)otherCar.getNrWheels(); i++)
	{
		const Wheel* newWheel = (otherCar.getWheel(i));
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());
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
		delete wheels[i]; // Delete the wheel itself,
		wheels[i] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
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
		return NULL;
	}
}

void Car::removeWheel(int index)
{
	if (0 <= index && index < getNrWheels())
	{
		delete wheels[index]; // Delete the wheel itself,
		wheels[index] = NULL; // and set the pointer to it to NULL to avoid messing with released memory.
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