#include "Truck.h"
#include "PackageException.h"

Truck::Truck(ManifestHeader in)
{
	_name = in.getDriverName();
	_baseWeight = _curWeight = in.getBaseWeight();
	newTrip(in.getOriginCity(), in.getDestCity());
	log("Name: "+ _name + "\nOrigin City: " + _originCity + "\nDestination City: " + _destCity + "\nBase Weight: " + std::to_string(_baseWeight)+"\n");
}

Truck::~Truck()
{
}

void Truck::newTrip(std::string originCity, std::string destCity)
{
	_originCity = originCity;
	_destCity = destCity;
}

void Truck::loadTruck(std::unique_ptr<Package>& pack)
{
	if (_numPackagesLoaded < PackageLimit)
	{
		_cargo->push_back(std::move(pack));

		std::vector<std::unique_ptr<Package>>* temp = _cargo.get();
		Package* temp2 = temp->back().get();

		_curWeight += temp2->getWeight();
		_curShippingCost += temp2->getShippingCost();
		_numPackagesLoaded++;
		log("Package #" + std::to_string(_numPackagesLoaded+1) + "\nTracking Number: " + std::to_string(temp2->getTrackingNumber())+"\nWeight: "+std::to_string(temp2->getWeight())+"\nShipping Cost: "+std::to_string(temp2->getShippingCost())+"\n");
	}
	else
	{
		PackageException er(pack, "Truck is full");
		throw er;
	}
}
