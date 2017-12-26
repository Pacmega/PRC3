#include "valveRow.h"

valveRow::valveRow()
{
	opened = false;
}

valveRow::~valveRow()
{
	
}

void valveRow::open()
{
	opened = true;
}

void valveRow::close()
{
	opened = false;
}