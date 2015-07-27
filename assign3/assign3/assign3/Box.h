#ifndef BOX_H
#define BOX_H
#pragma once
#include "Package.h"
class Box :
	public Package
{
public:
	Box(int trackingNumber, double weight) :Package(trackingNumber, weight){};
	virtual ~Box() {};
	virtual std::string getName()const override{ return "Box"; }
	virtual double getPricePerLb()const override{ return 2; }
	virtual double getMaxWeight()const override{ return 40; }
};
#endif
