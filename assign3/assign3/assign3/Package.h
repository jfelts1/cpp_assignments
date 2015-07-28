/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef PACKAGE_H
#define PACKAGE_H
#pragma once
#include <string>

class Package
{
public:
	Package(int trackingNumber=0,double weight=0, double shippingCost = 0);
	virtual ~Package();
	double getWeight(){return _weight;}
	int getTrackingNumber(){ return _trackingNunber; }
	double getShippingCost(){ return _shippingCost; }
	virtual std::string getName()const = 0;
private:
	double _weight=0;
	int _trackingNunber=0;
	double _shippingCost=0;
};

#endif
