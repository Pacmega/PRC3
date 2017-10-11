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

/* Commented so we can make use of this later to display everything
void ScanList::show()
{
    Scan* temp = head;
    std::cout << "\ncurrent scanlist: ";
    while (temp != NULL)
    {
        std::cout << temp->getValue() << " -> ";
        temp = temp->getNext();
    }
    std::cout << "NULL" << std::endl;
}
*/

void addScan(int serialNumber)
{
    
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

bool ScanList::removeScan(Scan* scanToRemove)
{
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
        // scanToRemove has been "cut out of the list"
        delete scanToRemove;
        scanToRemove = NULL;
        return true;
    }

    // scanToRemove is not in the list
    return false;
}

int getTImesRecycled(int serialNumber)
{
    return -1;
}