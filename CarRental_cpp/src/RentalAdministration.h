#ifndef _RENTALADMINISTRATION_H
#define _RENTALADMINISTRATION_H

#include <string>
#include "Car.h"

class RentalAdministration
{
public:
	RentalAdministration();
	~RentalAdministration();
	void Add(Car *car);
	bool RentCar(std::string licencePlate);
	double ReturnCar(std::string licencePlate, int kilometers);
};

#endif