#include <cstddef> // needed for definition of NULL
#include <iostream>

#include "ScanList.h"

ScanList::ScanList()
    : head(NULL)
{
}

ScanList::~ScanList()
{
    while (head != NULL)
    {
        Scan* temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
}

int ScanList::getNrElements()
{
    Scan* temp = head;
    int nrElements = 0;

    while (temp != NULL)
    {
        nrElements++;
        temp = temp->getNext();
    }

    return nrElements;
}

void ScanList::addScan(int serialNumber)
{
    if (serialNumber < 0)
    {

    }
}

Scan* ScanList::getScanByNr(int nr)
{
    if (nr < 0 || head == NULL)
    {
        return NULL;
    }

    Scan* temp = head;
    int i = 0;
    while (i < nr && temp != NULL)
    {
        i++;
        temp = temp->getNext();
    }

    return temp;
}

Scan* ScanList::getScanBySerialNr(int serialNumber)
{
    Scan* temp = head;

    while (temp != NULL)
    {
        if (temp->getSerialNumber() == serialNumber)
        {
            return temp;
        }
        else
        {
            temp = temp->getNext();
        }
    }

    return temp;
}

bool ScanList::removeScan(int serialNumber)
{
    if (serialNumber < 0 || serialNumber >= getNrElements())
    {
        return false;
    }

    Scan* scanToRemove = getScanBySerialNr(serialNumber);

    if (scanToRemove == head)
    {
        head = scanToRemove->getNext();
        delete scanToRemove;
        scanToRemove = NULL;
        return true;
    }

    Scan* temp = head;
    while (temp->getNext() != scanToRemove && temp != NULL)
    {
        temp = temp->getNext();
    }

    if (temp != NULL)
    {
        // temp is now pointing at the scan before scanToRemove
        temp->setNext(scanToRemove->getNext());
        // scanToRemove has been cut out of the list
        delete scanToRemove;
        scanToRemove = NULL;
        return true;
    }

    // scanToRemove is not in the list
    return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
    if (serialNumber >= 0 && serialNumber < getNrElements())
    {
        int timesRecycled = 0;
        Scan* temp = getScanBySerialNr(serialNumber);

        if (temp != NULL)
        {
            timesRecycled = temp->getTimesRecycled();
        }

        return timesRecycled;
    }

    return 0;
}
