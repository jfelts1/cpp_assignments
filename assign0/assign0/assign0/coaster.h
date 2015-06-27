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
