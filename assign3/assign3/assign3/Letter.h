#ifndef LETTER_H
#define LETTER_H
#pragma once
#include "Package.h"
#define OZ_PER_POUND 16
class Letter :
	public Package
{
public:
	Letter(int trackingNumber, double weight) :Package(trackingNumber, weight){};
	virtual ~Letter() {};
	virtual std::string getName()const override { return "Letter"; }
	virtual double getPricePerLb()const override { return 0.05/OZ_PER_POUND; }
	virtual double getMaxWeight()const override { return 32 / OZ_PER_POUND; }
};
#endif
