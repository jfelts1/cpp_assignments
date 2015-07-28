/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef BOX_H
#define BOX_H
#pragma once
#include "Package.h"
class Box :
	public Package
{
public:
	Box(int trackingNumber, double weight,double shippingCost) :Package(trackingNumber, weight,shippingCost){};
	virtual ~Box() {};
	virtual std::string getName()const override{ return "Box"; }
};
#endif
