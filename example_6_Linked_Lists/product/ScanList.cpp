#include <cstddef> // needed for definition of NULL
#include <iostream>

#include "ScanList.h"

ScanList::ScanList(void)
    : head(NULL)
{
}

ScanList::~ScanList(void)
{
    while (head != NULL)
    {
        Scan* temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
}

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

Scan* ScanList::getFirstScan(void)
{
    return head;
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

bool ScanList::insertAfter(Scan* newScan, Scan* scanToInsertAfter)
{
    if (newScan == NULL || scanToInsertAfter == NULL)
    {
        return false;
    }

    // look for scanToInsertAfter in list
    Scan* temp = head;
    while (temp != scanToInsertAfter && temp != NULL)
    {
        temp = temp->getNext();
    }

    if (temp != NULL)
    {
        // scanToInsertAfter was found in linked list, insert newScan
        newScan->setNext(scanToInsertAfter->getNext());
        scanToInsertAfter->setNext(newScan);
        return true;
    }

    // scanToInsertAfter was not found in linked list
    return false;
}

bool ScanList::insertBefore(Scan* newScan, Scan* scanToInsertBefore)
{
    if (scanToInsertBefore == head)
    {
        newScan->setNext(head);
        head = newScan;
        return true;
    }

    if (newScan == NULL || scanToInsertBefore == NULL)
    {
        return false;
    }

    Scan* temp = head;
    while (temp->getNext() != scanToInsertBefore && temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }

    if (temp->getNext() == scanToInsertBefore)
    {
        // temp is now pointing at the scan before scanToInsertBefore
        newScan->setNext(scanToInsertBefore);
        temp->setNext(newScan);
        return true;
    }

    // scanToInsertBefore was not found in linked list
    return false;
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
