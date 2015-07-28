#include "PackageFactory.h"
using std::string;
using std::unique_ptr;
using std::make_unique;

std::unique_ptr<Package> packageFactory(ManifestEntry entry)
{
	unique_ptr<Package> pack;
	
	string trNum = entry.getEntryTrackingNumberString();

	try
	{
		if (trNum.back() == '0')//letter
		{
			packageFactoryHelper(pack, entry, "Letter");
		}
		else if (trNum.back() == '1')//box
		{
			packageFactoryHelper(pack, entry, "Box");
		}
		else if (trNum.back() == '2')//wooden crate
		{
			packageFactoryHelper(pack, entry, "Wood Crate");
		}
		else if (trNum.back() == '3')//metal crate
		{
			packageFactoryHelper(pack, entry, "Metal Crate");
		}
		else
		{
			throw PackageException("Unknown Package");
		}
	}
	catch (const PackageException&)
	{
		throw;
	}
	return pack;
}

inline void packageFactoryHelper(std::unique_ptr<Package>& pack, ManifestEntry entry,string packName)
{
	int trackNum = entry.getEntryTrackingNumber();
	double weight = entry.getEntryWeight();

	pack = make_unique<MetalCrate>(trackNum, weight, pricePerLbMap.at(packName)*weight);
	if (weight > maxWeightMap.at(packName))
	{
		throw PackageException(pack, "Package too heavy");
	}

}
