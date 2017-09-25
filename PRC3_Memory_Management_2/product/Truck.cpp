#include "Truck.h"
#include <stdexcept>

Truck::Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power)
	: Car(model, material, diameter, nrWheels)
{
	if(power > 0) // Everything else is checked by the Car constructor.
	{
		*power = power;
	}
	else
	{
		throw std::invalid_argument("Impossible power");
	}
}

Truck::Truck(const Truck& myTruck)
	: Car(myTruck)
{
	*power = *(myTruck.power);
}

Truck::~Truck()
{
	delete power;
	power = NULL;
}

Truck& Truck::operator=(const Truck& myTruck)
{
	if (&myTruck == this) return *this; // Avoid changing yourself using yourself, that breaks everything
	
	//model = myTruck.model;

	for (int i = 0; i < getNrWheels(); i++)
	{
		removeWheel(i);
	}

	for (int i = 0; i < (int)myTruck.getNrWheels(); i++)
	{
		const Wheel* newWheel = (myTruck.getWheel(i));
		addWheel(newWheel->getDiameter(), newWheel->getMaterial());
	}

	return *this;
}

int Truck::getPower() const
{
	return *power;
}