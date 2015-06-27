/*
* James Felts
* Compilers used
* Visual C++  2013
* 
* Time took
* 30 minutes
*/

#include "coaster.h"

int main()
{
	int carSize = 0;
	int numCars = 0;
	int vehicleSize = 0;
	int peopleWaiting = 0;
	int numRuns = 0;

	while (!cin.eof())
	{
		readInput(carSize, numCars, peopleWaiting);
		vehicleSize = calculateVehicleSize(carSize, numCars);
		numRuns = calculateNumRuns(peopleWaiting, vehicleSize);

		cout <<"number of runs needed: "<< numRuns << endl;
	}

	return 0;
}