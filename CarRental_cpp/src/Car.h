#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
	public:
		// Con- and destructor
		Car(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, double pricePerKm);
		~Car();

		// Functions
		bool Rent();
		double Return(int kilometers);
		virtual void Clean() = 0;
		const std::string ToString();

		// Get functions
		const std::string GetManufacturer();
		const std::string GetModel();
		const int GetBuildYear();
		const std::string GetLicencePlate();
		const virtual bool GetNeedsCleaning() = 0;
		const int GetKilometers();
		const bool GetIsAvailable();

	private:
		// Variables
		std::string Manufacturer;
		std::string Model;
		int BuildYear;
		std::string LicencePlate;
		bool NeedsCleaning;
		int Kilometers;
		bool IsAvailable;
		double PricePerKm;
		int LastCleanedAtKm;
};

#endif