#include "valveRow.h"

valveRow::valveRow()
{
	opened = false;
}

valveRow::~valveRow()
{
	
}

// TODO: update return value in class diagram
void valveRow::open()
{
	opened = true;
}

// TODO: update return value in class diagram
void valveRow::close()
{
	opened = false;
}