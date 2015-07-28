/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef CRATE_H
#define CRATE_H
#pragma once
#include "Package.h"
class Crate :
	public Package
{
public:
	Crate(int trackingNumber=0, double weight=0,double shippingCost = 0) :Package(trackingNumber, weight,shippingCost){};
	virtual ~Crate() {};
};

#endif
