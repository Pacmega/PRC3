#ifndef SCANLIST_H
#define SCANLIST_H

#include "Scan.h"

class ScanList
{
private:
    Scan* head; // pointer to linked list of Scans

    int getNrElements(); // returns the number of elements present in the list.

public:
	ScanList();
	//	pre : -
	//	post: list is empty
	//

	virtual ~ScanList();
    //  pre : -
    //  post: all scans have been destructed withot memory leaks
    //

	void addScan (int serialNumber);
    // pre:  serialNumbers in the linked list are inascending order
	// post: IF serialNumber is not present in the list
	// THEN a new scan with serialNumber has been added in the right place
	//      to the list
	// ELSE timesRecycled has been increased by one

	Scan* getScanByNr(int serialNumber);
	// pre: -
	// post: IF a scan in the list has the given serialNumber
	// THEN return a pointer to the scan with that serialNumber
	// ELSE return NULL

	bool removeScan (int serialNumber);
	// pre:  serialNumbers are in ascending order in linked list scans
	// post: IF serialNumber is present in the list
	// THEN scan has been removed from the list and true has been returned
	// ELSE false has been returned

	int getTimesRecycled(int serialNumber);
	// pre:  serialNumbersin linked list scans are in ascending order
	// post: IF a scan with serialNumber is present in the list
	// THEN return the value of timesRecycled of that scan
	// ELSE return 0

};

#endif