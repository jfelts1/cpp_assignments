/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
#ifndef TRUCK_H
#define TRUCK_H
#pragma once
#include "Package.h"
#include "FileUtils.h"
#include <string>
#include <vector>
#include <memory>
#include <array>

class Truck
{
public:
	Truck(ManifestHeader in);
	virtual ~Truck();
	const int PackageLimit = 500;

	int getNumPackagesLoaded()const { return _numPackagesLoaded; }
	double getCurWeight()const { return _curWeight; }
	double getBaseWeight()const { return _baseWeight; }
	double getCurShippingCost()const{return _curShippingCost;}
	std::string getDriverName() const { return _name; }
	std::string getOriginCity()const{return _originCity;}
	std::string getDestCity()const { return _destCity; }
	void newTrip(std::string originCity, std::string destCity);
	void loadTruck(std::unique_ptr<Package>& pack);
	void leaveOrigin();
	void arriveDest();
	void unloadTruck();
private:
	int _numPackagesLoaded=0;
	std::string _name = "";
	std::string _originCity = "";
	std::string _destCity = "";
	double _curWeight = 0;
	double _baseWeight = 0;
	double _curShippingCost = 0;
	std::unique_ptr<std::vector<std::unique_ptr<Package>>> _cargo = std::make_unique<std::vector<std::unique_ptr<Package>>>();
};

#endif
