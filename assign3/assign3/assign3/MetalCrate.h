#ifndef METALCRATE_H
#define METALCRATE_H
#pragma once
#include "Crate.h"
class MetalCrate :
	public Crate
{
public:
	MetalCrate(int trackingNumber, double weight,double shippingCost) :Crate(trackingNumber, weight,shippingCost){}
	virtual ~MetalCrate() {}
	virtual const std::string getName()const override { return "Metal Crate"; }
};

#endif
