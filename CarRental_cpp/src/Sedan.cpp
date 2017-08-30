#include <stdexcept>
#include <cstddef>
#include <string>
using namespace std;

#include "Sedan.h"

Sedan::Sedan(string manufacturer, string model, int buildYear, string licencePlate, int hasTowbar)
 : Car( manufacturer, model, buildYear, licencePlate, pricePerKm)
{
	HasTowbar = hasTowbar;
	lastCleanedAtKm = 0;
}

void Sedan::Clean()
{
	lastCleanedAtKm = kilometers;
}