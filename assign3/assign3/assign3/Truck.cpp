#include "Truck.h"
using namespace std;

Truck::Truck(string name)
{
	_name = name;
}


Truck::~Truck()
{
}

void Truck::newTrip(std::string originCity, std::string destCity)
{
	_originCity = originCity;
	_destCity = destCity;
}

void Truck::loadTruck(std::unique_ptr<vector<Package>>& cargo)
{
	_cargo = move(cargo);
}
