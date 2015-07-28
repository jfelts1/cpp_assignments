/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
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
