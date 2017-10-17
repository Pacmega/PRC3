#include <cstddef> // needed for definition of NULL
#include <iostream>
#include <stdexcept>

#include "Scan.h"

Scan::Scan(int number)
{
	if (number < 0)
	{
		throw std::out_of_range("Invalid serial number");
	}
	else
	{
		serialNumber = number;
		timesRecycled = 0;
		this->next = NULL;
	}
}

Scan::~Scan()
{
	//delete next;
	//next = NULL;
}

int Scan::getSerialNumber() const
{
	return serialNumber;
}

Scan* Scan::getNext()
{
	return next;
}

void Scan::setNext(Scan* nextScan)
{
	next = nextScan;
}

void Scan::recycle()
{
	timesRecycled++;
}

int Scan::getTimesRecycled() const
{
	return timesRecycled;
}