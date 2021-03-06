#ifndef _SEDAN_H
#define _SEDAN_H

class Sedan : public Car
{
	public:
		Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar, double pricePerKm);
		void Clean(int kilometers);
		const bool GetNeedsCleaning();
		const bool GetHasTowbar();

	private:
		// Variables
		bool NeedsCleaning;
		bool HasTowbar;
		int LastCleanedAtKm;
};
#endif