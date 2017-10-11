/*
 *  main.cpp
 *
 *  Created on: Sep 25, 2013
 *  Author: P. Lambooij
 */

#include <string>
#include <iostream>

#include "ScanList.h"
#include "Scan.h"

int main()
{
  std::cout << "Illustration Linked List Operations\n";

  ScanList* MyScanList = new ScanList();
  Scan* newScan;
  Scan* position;

  MyScanList->show();

  newScan = new Scan(10);
  MyScanList->insertBefore(newScan, NULL);
  MyScanList->show();

  newScan = new Scan(20);
  position = MyScanList->getScanByNr(0);
  MyScanList->insertAfter(newScan, position);
  MyScanList->show();

  newScan = new Scan(30);
  position = MyScanList->getScanByNr(1);
  MyScanList->insertBefore(newScan, position);
  MyScanList->show();

  newScan = new Scan(40);
  position = MyScanList->getScanByNr(2);
  MyScanList->insertAfter(newScan, position);
  MyScanList->show();

  position = MyScanList->getScanByNr(1);
  MyScanList->removeScan(position);
  MyScanList->show();

  std::cout << "\ndeleting ScanList";
  delete MyScanList;
  MyScanList = NULL;
  
  std::cout << std::endl;
}
