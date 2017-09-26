#include "Wheel.h"
#include <stdexcept>

Wheel::Wheel(int diameter, const std::string& material)
{
	if (diameter > 0 && material != "")
	{
		this->diameter = diameter;
		this->material = material;
	}
	else
	{
		throw std::out_of_range("Impossible diameter");
	}
}

const std::string& Wheel::getMaterial() const
{
	return material;
}

void Wheel::setMaterial(const std::string& material)
{
	this->material = material;
}

int Wheel::getDiameter() const
{
	return diameter;
}