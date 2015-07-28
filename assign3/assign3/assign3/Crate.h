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
