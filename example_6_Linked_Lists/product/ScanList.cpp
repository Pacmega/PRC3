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
            // std::cout << "Created new head with " << serialNumber << std::endl;
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
                    // std::cout << "Recycled serial number " << serialNumber << std::endl;
                    
                    break; // Don't continue iterating through the list and waste resources
                }
                else if (temp->getNext() == NULL)
                {
                    // Reached the end of the list, scan does not exist yet

                    Scan* newScan = new Scan(serialNumber);
                    temp->setNext(newScan);
                    // std::cout << "Added serial number " << serialNumber << " last in line" << std::endl;

                    break; // Don't continue iterating through the list and waste resources
                }
                else if (temp->getNext()->getSerialNumber() > serialNumber)
                {
                    // If the next scan has a larger serialNumber,
                    // the new scan should go just in front of it.

                    Scan* newScan = new Scan(serialNumber);
                    newScan->setNext(temp->getNext());
                    temp->setNext(newScan);
                    // std::cout << "Added serial number " << serialNumber << " just before " << temp->getNext()->getSerialNumber() << std::endl;

                    break; // Don't continue iterating through the list and waste resources
                }

                temp = temp->getNext();
            }
        }
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
    // std::cout << "serialNumber to find: " << serialNumber << std::endl;

    while (temp != NULL)
    {
        // std::cout << "serialNumber of this temp: " << temp->getSerialNumber() << std::endl;

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

    Scan* scanToRemove = getScanBySerialNr(serialNumber);

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
        Scan* temp = getScanBySerialNr(serialNumber);

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
