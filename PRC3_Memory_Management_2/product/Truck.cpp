#include "Truck.h"
#include <stdexcept>

Truck::Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power)
: Car(model, material, diameter, nrWheels)
{
	
	if(power > 0) // Everything else is checked by the Car constructor.
	{
		
		this->power = &power;
	}
	else
	{
		throw std::out_of_range("Impossible power");
	}
}

Truck::Truck(const Truck& myTruck)
: Car(myTruck)
{
	this->power = myTruck.power;
}

Truck& Truck::operator=(const Truck& myTruck)
{
	if (&myTruck == this) return *this; // Avoid changing yourself using yourself, that breaks everything
	
	this->power = myTruck.power;

	return *this;
}

Truck::~Truck()
{
	delete power;
}

int Truck::getPower() 
{
	return *power;
}