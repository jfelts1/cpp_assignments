#ifndef BOX_H
#define BOX_H
#pragma once
#include "Package.h"
class Box :
	public Package
{
public:
	Box(int trackingNumber, double weight, double shippingCost) :Package(trackingNumber, weight, shippingCost){};
	virtual ~Box();
};
#endif
