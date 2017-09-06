#include <string>
#include <vector>

#include "Car.h"
#include "RentalAdministration.h"

RentalAdministration::RentalAdministration()
{

}

RentalAdministration::~RentalAdministration()
{
	delete &Cars;
}

void RentalAdministration::Add(Car *car)
{
	if (car != NULL)
	{
		Cars.push_back(car);
	}
}

bool RentalAdministration::RentCar(std::string licencePlate)
{
	for (int i = 0; i < Cars.size(); i++)
	{
		if (Cars[i]->GetLicencePlate() == licencePlate && Cars[i]->GetIsAvailable() == true)
		{
			if (Cars[i]->Rent())
			{
				return true;
			}
		}
	}

	return false;
}

double RentalAdministration::ReturnCar(std::string licencePlate, int kilometers)
{
	for (int i = 0; i < Cars.size(); i++)
	{
		if (Cars[i]->GetLicencePlate() == licencePlate && Cars[i]->GetIsAvailable() == false)
		{
			int result = Cars[i]->Return(kilometers);
			return result;
		}
	}
	
	return -1;
}
