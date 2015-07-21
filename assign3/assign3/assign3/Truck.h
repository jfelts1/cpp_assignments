#ifndef TRUCK_H
#define TRUCK_H
#pragma once
#include "Package.h"
#include <string>
#include <vector>
#include <memory>

class Truck
{
public:
	Truck(std::string name);
	virtual ~Truck();
	const int PackageLimit = 500;

	int getNumPackagesLoaded()const { return _numPackagesLoaded; }
	std::string getDriverName() const { return _name; }
	std::string getOriginCity()const{return _originCity;}
	std::string getDestCity()const { return _destCity; }
	void newTrip(std::string originCity, std::string destCity);
	void loadTruck(std::unique_ptr<std::vector<Package>>& cargo);
private:
	int _numPackagesLoaded=0;
	std::string _name = "";
	std::string _originCity = "";
	std::string _destCity = "";
	double _curWeight = 0;
	std::unique_ptr<std::vector<Package>> _cargo = nullptr;
};

#endif