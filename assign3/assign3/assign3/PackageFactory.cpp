#include "PackageFactory.h"
using namespace std;

std::unique_ptr<Package> packageFactory(ManifestEntry entry)
{
	unique_ptr<Package> pack;
	
	string trNum = entry.getEntryTrackingNumberString();

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
			PackageException er("Unknown Package");
			throw er;
		}
	}
	catch (const PackageException&)
	{
		throw;
	}
	return pack;
}

template<class T>
inline void packageFactoryHelper(std::unique_ptr<Package>& pack, ManifestEntry entry,string packName)
{
	int trackNum = entry.getEntryTrackingNumber();
	double weight = entry.getEntryWeight();

	pack = make_unique<T>(trackNum, weight, pricePerLbMap.at(packName)*weight);
	if (weight > maxWeightMap.at(packName))
	{
		PackageException er(pack, "Package too heavy");
		throw er;
	}

}
