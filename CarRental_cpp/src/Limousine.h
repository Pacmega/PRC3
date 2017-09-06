#ifndef _LIMOUSINE_H
#define _LIMOUSINE_H

#include "Car.h"

class Limousine : public Car	
{
	public:
		// Functions
		Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar, double pricePerKm);
		~Limousine();
		double Return(int kilometers);
		void Clean();
		const bool GetNeedsCleaning();
		const bool GetHasMinibar();

	private:
		// Variables
		double pricePerKm;
		bool NeedsCleaning;	
		bool HasMinibar;
};
#endif