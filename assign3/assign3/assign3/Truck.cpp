#include "Truck.h"
#include "PackageException.h"
using std::string;
using std::unique_ptr;
using std::vector;
using std::to_string;

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
		log("Package #" + to_string(_numPackagesLoaded+1) + "\nTracking Number: " + to_string(temp2->getTrackingNumber())+"\nWeight: "+to_string(temp2->getWeight())+"\nShipping Cost: "+to_string(temp2->getShippingCost())+"\n");
	}
	else
	{
		throw PackageException(pack,"Truck is full.");
	}
}
