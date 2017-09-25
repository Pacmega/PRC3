#include "Truck.h"

Truck::Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power)
	: Car(model, material, diameter, nrWheels)
{
	// TODO
}

Truck::Truck(const Truck& myTruck)
	: Car(myTruck)
{
	// TODO
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

Truck::~Truck()
{
	delete power;
	power = NULL;
}

int Truck::getPower() const
{
	return *power;
}