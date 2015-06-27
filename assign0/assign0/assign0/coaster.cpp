#include "coaster.h"

int calculateVehicleSize(int carSize, int numCars)
{
	return carSize*numCars;
}

void readInput(int& carSize, int& numCars, int& peopleWaiting)
{
	carSize = readCarSize();
	numCars = readNumCars();
	peopleWaiting = readPeopleWaiting();
}

int readCarSize()
{
	int temp = 0;
	cin >> temp;
	return temp;
}

int readNumCars()
{
	int temp = 0;
	cin >> temp;
	return temp;
}

int readPeopleWaiting()
{
	int temp = 0;
	cin >> temp;
	return temp;
}

int calculateNumRuns(int peopleWaiting, int vehicleSize)
{
	int temp = peopleWaiting % vehicleSize;
	int temp2 = peopleWaiting / vehicleSize;
	if (temp == 0)
	{
		return temp2;
	}
	else
	{
		//since temp was non zero 1 more run is needed to get everyone through
		return temp2 + 1;
	}
}
