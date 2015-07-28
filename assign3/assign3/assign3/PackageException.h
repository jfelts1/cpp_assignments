#ifndef PACKAGEEXCEPTION_H
#define PACKAGEEXCEPTION_H
#pragma once
#include "Package.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <memory>
class PackageException :public std::runtime_error
{
public:
	PackageException(std::unique_ptr<Package>& pack, const char* message);
	PackageException(std::unique_ptr<Package>& pack, std::string message);
	PackageException(const char * message);
	PackageException(std::string message);
	PackageException(PackageException& pack);
	virtual ~PackageException() {};
	virtual int getPackageTrackingNumber()const { return _packageTrackingNumber; }
	virtual double getPackageWeight()const { return _packageWeight; }
	virtual std::string getNameOfPackage()const { return _packageName; }
private:
	std::string _packageName = "Unknown";
	double _packageWeight = 0;
	int _packageTrackingNumber = 0;
};

#endif
