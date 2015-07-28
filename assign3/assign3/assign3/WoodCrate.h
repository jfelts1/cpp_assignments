/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
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
