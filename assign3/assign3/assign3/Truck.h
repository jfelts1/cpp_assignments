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
	Truck(std::array<std::string,MANIFEST_HEADER_SIZE> in);
	virtual ~Truck();
	const int PackageLimit = 500;

	int getNumPackagesLoaded()const { return _numPackagesLoaded; }
	double getCurWeight()const { return _curWeight; }
	double getBaseWeight()const { return _baseWeight; }
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
	double _baseWeight = 0;
	std::unique_ptr<std::vector<Package>> _cargo = nullptr;
};

#endif