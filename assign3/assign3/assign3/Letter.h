/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef LETTER_H
#define LETTER_H
#pragma once
#include "Package.h"

class Letter :
	public Package
{
public:
	Letter(int trackingNumber, double weight,double shippingCost) :Package(trackingNumber, weight,shippingCost){};
	virtual ~Letter() {};
	virtual std::string getName()const override { return "Letter"; }
};
#endif
