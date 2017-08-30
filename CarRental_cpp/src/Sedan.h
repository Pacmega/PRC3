#ifndef _SEDAN_H
#define _SEDAN_H

class Sedan
{
	public:
		Sedan(string manufacturar, string model, int buildYear, string licencePlate, bool hasTowbar);
		~Sedan();
		void Clean();

		bool HasTowbar;
		bool NeedsCleaning;
	
};
#endif