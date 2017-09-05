#include <string>
#include <vector>

#include "Car.h"
#include "RentalAdministration.h"

RentalAdministration::RentalAdministration()
{

}

RentalAdministration::~RentalAdministration()
{

}

void RentalAdministration::Add(Car *car)
{
	Cars.push_back(car);
}

bool RentalAdministration::RentCar(std::string licencePlate)
{
	for (int i = 0; i < Cars.size(); i++)
	{
		if (Cars[i]->LicencePlate == licencePlate && Cars[i]->IsAvailable == true)
		{
			Cars[i]->IsAvailable = false;
			return true;
		}
	}

	return false;
}

double RentalAdministration::ReturnCar(std::string licencePlate, int kilometers)
{
	for (int i = 0; i < Cars.size(); i++)
	{
		if (Cars[i]->LicencePlate == licencePlate && Cars[i]->IsAvailable == false)
		{
			int result = Cars[i]->Return(kilometers);
			return result;
		}
	}
	
	return -1;
}
