#ifndef _LIMOUSINE_H
#define _LIMOUSINE_H

#include "Car.h"

class Limousine// : public Car
{
	public:
		// Functions
		Limousine(string manufacturer, string model, int buildYear, string licencePlate, bool hasMinibar);
		~Limousine();
		double Return(int kilometers);
		void Clean();

		// Variables
		bool HasMinibar;
		bool NeedsCleaning;	
};
#endif