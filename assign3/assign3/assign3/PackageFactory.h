#ifndef PACKAGEFACTORY_H
#define PACKAGEFACTORY_H
#include "Box.h"
#include "Crate.h"
#include "Letter.h"
#include "MetalCrate.h"
#include "PackageException.h"
#include "WoodCrate.h"
#include "Truck.h"
#include <memory>
#include <string>
#include <map>
#define OZ_PER_POUND 16

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

template<class T>
inline void packageFactoryHelper(std::unique_ptr<Package>& pack, ManifestEntry entry, std::string packName)
{
	int trackNum = entry.getEntryTrackingNumber();
	double weight = entry.getEntryWeight();

	pack = std::make_unique<T>(trackNum, weight, pricePerLbMap.at(packName)*weight);
	if (weight > maxWeightMap.at(packName))
	{
		PackageException er(pack, "Package too heavy");
		throw er;
	}
}

std::unique_ptr<Package> packageFactory(ManifestEntry entry)
{
	std::unique_ptr<Package> pack;

	std::string trNum = entry.getEntryTrackingNumberString();

	try
	{
		if (trNum.back() == '0')//letter
		{
			packageFactoryHelper<Letter>(pack, entry, "Letter");
		}
		else if (trNum.back() == '1')//box
		{
			packageFactoryHelper<Box>(pack, entry, "Box");
		}
		else if (trNum.back() == '2')//wooden crate
		{
			packageFactoryHelper<WoodCrate>(pack, entry, "Wood Crate");
		}
		else if (trNum.back() == '3')//metal crate
		{
			packageFactoryHelper<MetalCrate>(pack, entry, "Metal Crate");
		}
		else
		{
			PackageException er("Unkown Package");
			throw er;
		}
	}
	catch (const PackageException&)
	{
		throw;
	}
	return pack;
}

#endif
