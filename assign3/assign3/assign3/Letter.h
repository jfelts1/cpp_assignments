#ifndef LETTER_H
#define LETTER_H
#pragma once
#include "Package.h"

class Letter :
	public Package
{
public:
	Letter(int trackingNumber, double weight,double shippingCost) :Package(trackingNumber, weight,shippingCost){}
	virtual ~Letter() {}
	virtual const std::string getName()const override { return "Letter"; }
};
#endif
