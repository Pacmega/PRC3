#ifndef _LIMOUSINE_H
#define _LIMOUSINE_H

#include "Car.h"

class Limousine : public Car	
{
	public:
		// Functions
		Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar);
		~Limousine();
		double Return(int kilometers);
		void Clean();
		const bool GetNeedsCleaning();

		// Variables
		bool HasMinibar;
		bool NeedsCleaning;	

	private:
		double pricePerKm;
};
#endif