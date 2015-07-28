#include "Package.h"


Package::Package(int trackingNumber,double weight, double shippingCost)
{
	_weight = weight;
	_trackingNunber = trackingNumber; 
	_shippingCost = shippingCost;
}


Package::~Package()
{
}
