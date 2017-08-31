#ifndef _RENTALADMINISTRATION_H
#define _RENTALADMINISTRATION_H

#include <string>
#include <vector>
#include "Car.h"

class RentalAdministration
{
	public:
		std::vector<Car*> Cars;
		RentalAdministration();
		~RentalAdministration();
		void Add(Car *car);
		bool RentCar(std::string licencePlate);
		double ReturnCar(std::string licencePlate, int kilometers);
};

#endif