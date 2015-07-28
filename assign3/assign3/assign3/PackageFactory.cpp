/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*
* Every entry in the log is timestamped withthe current UTC
*/
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
			int trackNum = entry.getEntryTrackingNumber();
			double weight = entry.getEntryWeight()/OZ_PER_POUND;

			pack = make_unique<Letter>(trackNum, weight, pricePerLbMap.at("Letter")*weight);
			if (weight > maxWeightMap.at("Letter"))
			{
				PackageException er(pack, "Package too heavy");
				throw er;
			}
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
			PackageException er(entry.getEntryTrackingNumber(),entry.getEntryWeight(),"Unknown Package");
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
