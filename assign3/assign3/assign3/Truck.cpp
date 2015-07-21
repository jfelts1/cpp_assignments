#include "Truck.h"
using namespace std;

Truck::Truck(std::array<std::string, MANIFEST_HEADER_SIZE> in)
{
	_name = in[0];
	_baseWeight = _curWeight = stod(in[1]);
	newTrip(in[2], in[3]);
	log("Name: "+ _name + "\nOrigin City: " + _originCity + "\nDestination City: " + _destCity + "\nBase Weight: " + to_string(_baseWeight)+"\n");
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
