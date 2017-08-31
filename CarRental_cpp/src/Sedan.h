#ifndef _SEDAN_H
#define _SEDAN_H

class Sedan : public Car
{
	public:
		Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar);
		~Sedan();
		void Clean();
		const bool GetNeedsCleaning();

		bool HasTowbar;
		bool NeedsCleaning;

	private:
		double pricePerKm;
};
#endif