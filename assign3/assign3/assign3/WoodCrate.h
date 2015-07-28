#ifndef WOODCRATE_H
#define WOODCRATE_H
#pragma once
#include "Crate.h"
class WoodCrate :
	public Crate
{
public:
	WoodCrate(int trackingNumber, double weight,double shippingCost) :Crate(trackingNumber, weight,shippingCost){};
	virtual ~WoodCrate() {};
	virtual std::string getName()const override { return "Wood Crate"; }
};
#endif
