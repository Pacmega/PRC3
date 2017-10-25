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
        throw std::out_of_range("Invalid serial number");
    }
    else
    {
        if (head == NULL)
        {
            Scan* newScan = new Scan(serialNumber);
            head = newScan;
        }
        else
        {
            Scan* temp = head;

            while (temp != NULL)
            {
                if (temp->getSerialNumber() == serialNumber)
                {
                    // Found the scan in the list
                    
                    temp->recycle();
                    
                    break; // Don't continue iterating through the list and waste resources
                }
                else if (temp->getNext() == NULL)
                {
                    // Reached the end of the list, scan does not exist yet

                    Scan* newScan = new Scan(serialNumber);
                    temp->setNext(newScan);

                    break; // Don't continue iterating through the list and waste resources
                }
                else if (temp->getNext()->getSerialNumber() > serialNumber)
                {
                    // If the next scan has a larger serialNumber,
                    // the new scan should go just in front of it.

                    Scan* newScan = new Scan(serialNumber);
                    newScan->setNext(temp->getNext());
                    temp->setNext(newScan);

                    break; // Don't continue iterating through the list and waste resources
                }

                temp = temp->getNext();
            }
        }
    }
}

Scan* ScanList::getScanByNr(int serialNumber)
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
    if (serialNumber < 0)
    {
        return false;
    }

    Scan* scanToRemove = getScanByNr(serialNumber);

    if (scanToRemove == NULL)
    {
        return false;
    }

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
    if (serialNumber >= 0)
    {
        int timesRecycled = 0;
        Scan* temp = getScanByNr(serialNumber);

        if (temp != NULL)
        {
            timesRecycled = temp->getTimesRecycled();
        }

        return timesRecycled;
    }
    else
    {
        throw std::out_of_range("Invalid serial number");
    }
}
