#include "Wheel.h"
#include <stdexcept>

Wheel::Wheel(int diameter, const std::string& material)
{
	// Diameter is already checked in car
	if (material != "")
	{
		this->diameter = diameter;
		setMaterial(material);
	}
	else
	{
		throw std::out_of_range("Impossible material");
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