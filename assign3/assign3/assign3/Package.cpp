#include "Package.h"


Package::Package(int trackingNumber,double weight)
{
	_weight = weight;
	_trackingNunber = trackingNumber; 
	_shippingCost = weight*getPricePerLb();
}


Package::~Package()
{
}
