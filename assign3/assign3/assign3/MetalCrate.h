#ifndef METALCRATE_H
#define METALCRATE_H
#pragma once
#include "Crate.h"
class MetalCrate :
	public Crate
{
public:
	MetalCrate(int trackingNumber, double weight) :Crate(trackingNumber, weight){};
	virtual ~MetalCrate() {};
	virtual std::string getName()const override { return "Metal Crate"; }
	virtual double getPricePerLb()const override { return 3; }
	virtual double getMaxWeight()const override { return 100; }
};

#endif