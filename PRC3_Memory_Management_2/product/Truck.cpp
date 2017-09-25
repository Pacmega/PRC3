#include "Truck.h"

Truck::Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power)
	: Car(model, material, diameter, nrWheels)
{
	// TODO
}

Truck::Truck(const Truck& myTruck)
	: Car(myTruck.model, myTruck.material, myTruck.diameter, myTruck.nrWheels)
{
	// TODO
}

Truck& Truck::operator=(const Truck& myTruck)
{
	if (&myTruck == this) return *this; // Avoid changing yourself using yourself, that breaks everything
	
	model = myTruck.model;

	// TODO: remove wheels & add new wheels
}

Truck::~Truck()
{
	delete power;
	power = NULL;
}

int Truck::getPower()
{
	return *power;
}