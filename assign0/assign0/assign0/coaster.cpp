/*
* James Felts
* Compilers used
* Visual C++  2013
* G++ 4.9.2
* 
* Time took
* 30 minutes
*/

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
	cin.clear();
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

void displayNumRuns(int peopleWaiting, int vehicleSize)
{
	if(vehicleSize != 0)
	{
		int temp = peopleWaiting % vehicleSize;
		int numRuns = peopleWaiting / vehicleSize;
		if (temp != 0)
		{
			//since temp was non zero one more run is needed to get everyone through
			numRuns+= 1;
		}
		cout <<"number of runs needed: "<< numRuns << endl;
	}
	else
	{
		cout << "vehicle has no size!" << endl;
	}
	
}
