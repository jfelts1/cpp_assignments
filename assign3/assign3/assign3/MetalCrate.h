/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef METALCRATE_H
#define METALCRATE_H
#pragma once
#include "Crate.h"
class MetalCrate :
	public Crate
{
public:
	MetalCrate(int trackingNumber, double weight,double shippingCost) :Crate(trackingNumber, weight,shippingCost){};
	virtual ~MetalCrate() {};
	virtual std::string getName()const override { return "Metal Crate"; }
};

#endif
