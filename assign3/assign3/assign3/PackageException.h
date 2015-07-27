#ifndef PACKAGEEXCEPTION_H
#define PACKAGEEXCEPTION_H
#pragma once
#include "Package.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <memory>
class PackageException :public std::exception
{
public:
	PackageException(std::unique_ptr<Package>& pack, const char* message);
	virtual ~PackageException() {};
	virtual const char* what()const noexcept override { return _message; }
	virtual std::string getName()const { return _pack->getName(); }
	virtual double getPricePerLb()const { return _pack->getPricePerLb(); }
	virtual double getMaxWeight()const { return _pack->getMaxWeight(); }
private:
	const char* _message;
	std::unique_ptr<Package> _pack;
};

#endif
