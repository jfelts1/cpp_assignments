#ifndef PACKAGEEXCEPTION_H
#define PACKAGEEXCEPTION_H
#pragma once
#include "Package.h"
#include <exception>
#include <stdexcept>
class PackageException :
	public Package, public std::exception
{
public:
	PackageException(int trackingNumber, double weight, double shippingCost) :Package(trackingNumber, weight, shippingCost){};
	virtual ~PackageException();
};

#endif