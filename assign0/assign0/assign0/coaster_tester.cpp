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
	bool quit = false;
	//execute in a loop until user says quit
	while (cin.peek() != 'q' && !quit)
	{
		readInput(carSize, numCars, peopleWaiting);
		vehicleSize = calculateVehicleSize(carSize, numCars);
		displayNumRuns(peopleWaiting, vehicleSize);
		if(carSize == 0 && numCars == 0 && peopleWaiting == 0)
		{
			quit = true;
		}
	}
	return 0;
}
