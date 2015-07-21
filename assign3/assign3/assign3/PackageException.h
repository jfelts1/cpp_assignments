#ifndef PACKAGEEXCEPTION_H
#define PACKAGEEXCEPTION_H
#pragma once
#include "Package.h"
#include <exception>
#include <stdexcept>
#include <string>
class PackageException :
	public Package, public std::exception
{
public:
	PackageException(int trackingNumber, double weight, double shippingCost, const char* message) :Package(trackingNumber, weight, shippingCost), exception() { _message = message; };
	virtual ~PackageException() {};
	virtual const char* what()const override { return _message; }
private:
	const char* _message;
};

#endif