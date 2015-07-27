#ifndef WOODCRATE_H
#define WOODCRATE_H
#pragma once
#include "Crate.h"
class WoodCrate :
	public Crate
{
public:
	WoodCrate(int trackingNumber, double weight) :Crate(trackingNumber, weight){};
	virtual ~WoodCrate() {};
	virtual std::string getName()const override { return "Wood Crate"; }
	virtual double getPricePerLb()const override { return 2.5; }
	virtual double getMaxWeight()const override { return 80; }
};
#endif
