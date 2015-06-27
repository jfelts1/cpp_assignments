/*
* James Felts
* Compilers used
* Visual C++  2013
* G++ 4.9.2
* 
* Time took
* 30 minutes
*/

#ifndef COASTER_H
#define COASTER_H
#include <iostream>
using namespace std;

int calculateVehicleSize(int carSize, int numCars);
void readInput(int& carSize, int& numCars, int& peopleWaiting);
int readCarSize();
int readNumCars();
int readPeopleWaiting();
void displayNumRuns(int peopleWaiting, int vehicleSize);


#endif
