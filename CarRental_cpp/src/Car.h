#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
	public:
		// Con- and destructor
		Car(string manufacturer, string model, int buildYear, string licencePlate, double pricePerKm);
		~Car();

		// Variables
		const string Manufacturer;
		const string Model;
		const int BuildYear;
		const string LicencePlate;
		bool NeedsCleaning; // TODO: should be abstract, but how?
		int Kilometers;
		bool IsAvailable;

		// Functions
		bool Rent();
		double Return(int kilometers);
		virtual void Clean() = 0;
		const string ToString();

		// Additional functions
		string GetManufacturer();
		string GetModel();
		int GetBuildYear();
		string GetLicencePlate();
		virtual bool GetNeedsCleaning() = 0;
		int GetKilometers();
		bool GetIsAvailable();

	private:
		double pricePerKm;
};

#endif