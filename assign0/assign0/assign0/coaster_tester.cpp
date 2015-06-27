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

int main()
{
	int carSize = 0;
	int numCars = 0;
	int vehicleSize = 0;
	int peopleWaiting = 0;

	//execute in a loop
	while (!cin.eof())
	{
		readInput(carSize, numCars, peopleWaiting);
		vehicleSize = calculateVehicleSize(carSize, numCars);
		displayNumRuns(peopleWaiting, vehicleSize);

	}

	return 0;
}
