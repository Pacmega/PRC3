#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
	public:
		// Con- and destructor
		Car(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, double pricePerKm);
		~Car();

		// Variables
		const std::string Manufacturer;
		const std::string Model;
		const int BuildYear;
		const std::string LicencePlate;
		bool NeedsCleaning;
		int Kilometers;
		bool IsAvailable;

		// Functions
		bool Rent();
		double Return(int kilometers);
		virtual void Clean() = 0;
		const std::string ToString();

		// Additional functions
		std::string GetManufacturer();
		std::string GetModel();
		int GetBuildYear();
		std::string GetLicencePlate();
		virtual bool GetNeedsCleaning() = 0;
		int GetKilometers();
		bool GetIsAvailable();

	private:
		double pricePerKm;
};

#endif