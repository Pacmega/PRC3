#include "valveRow.h"

valveRow::valveRow(communicationHandler cHandler)
{
	handler = cHandler;
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