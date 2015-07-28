#ifndef PACKAGE_H
#define PACKAGE_H
#pragma once
#include <string>
#include <map>
#define OZ_PER_POUND 16
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

//some maps that make changing these values simpler than going to each Package type to change them
const std::map<std::string, double> pricePerLbMap =
{
	{ "Letter",0.05 / OZ_PER_POUND },
	{ "Box",2 },
	{ "Metal Crate",3 },
	{ "Wood Crate",2.5 }
};

const std::map<std::string, double> maxWeightMap =
{
	{ "Letter",32 / OZ_PER_POUND },
	{ "Box",40 },
	{ "Metal Crate",100 },
	{ "Wood Crate",80 }
};

#endif