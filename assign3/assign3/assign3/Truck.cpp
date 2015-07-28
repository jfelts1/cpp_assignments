/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#include "Truck.h"
#include "PackageException.h"
using namespace std;

Truck::Truck(ManifestHeader in)
{
	_name = in.getDriverName();
	_baseWeight = _curWeight = in.getBaseWeight();
	newTrip(in.getOriginCity(), in.getDestCity());
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

void Truck::loadTruck(unique_ptr<Package>& pack)
{
	if (_numPackagesLoaded < PackageLimit)
	{
		_cargo->push_back(move(pack));

		vector<unique_ptr<Package>>* temp = _cargo.get();
		Package* temp2 = temp->back().get();

		_curWeight += temp2->getWeight();
		_curShippingCost += temp2->getShippingCost();
		_numPackagesLoaded++;
		log("Loading "+temp2->getName()+"\nTracking Number: " + to_string(temp2->getTrackingNumber())+"\nWeight: "+to_string(temp2->getWeight())+\
			"\nShipping Cost: "+to_string(temp2->getShippingCost())+"\n");
	}
	else
	{
		PackageException er(pack, "Truck is full");
		throw er;
	}
}

void Truck::leaveOrigin()
{
	log("Leaving " + _originCity + "\n");
}

void Truck::arriveDest()
{
	log("Arrived at " + _destCity + "\n");
}

void Truck::unloadTruck()
{
	int i = 0;
	for (i = 0;i < _cargo->size();i++)
	{
		log("Unloading "+_cargo->at(i)->getName()+"\nTracking Number: " + to_string(_cargo->at(i)->getTrackingNumber())+"\nWeight: "+to_string(_cargo->at(i)->getWeight())+\
			"\nShipping Cost: "+to_string(_cargo->at(i)->getShippingCost())+"\n");
		_numPackagesLoaded--;
	}

}


