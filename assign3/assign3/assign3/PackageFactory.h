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

std::unique_ptr<Package> packageFactory(ManifestEntry in);
template<class t>
void packageFactoryHelper(std::unique_ptr<Package>& pack,ManifestEntry entry,std::string packName);



#endif
