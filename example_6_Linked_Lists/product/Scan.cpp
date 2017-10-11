#include <cstddef> // needed for definition of NULL
#include <iostream>

#include "Scan.h"

Scan::Scan(int number)
{
	serialNumber = number;
	timesRecycled = 0;
}

Scan::~Scan()
{
	delete next;
	next = NULL;
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