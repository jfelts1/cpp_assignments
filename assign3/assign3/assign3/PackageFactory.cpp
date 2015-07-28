#include "PackageFactory.h"
using namespace std;

std::unique_ptr<Package> packageFactory(ManifestEntry in)
{
	unique_ptr<Package> pack;
	int trackNum = in.getEntryTrackingNumber();
	double weight = in.getEntryWeight();
	string trNum = in.getEntryTrackingNumberString();

	if (trNum.back() == '0')//letter
	{
		pack = make_unique<Letter>(trackNum, weight, pricePerLbMap.at("Letter")*weight);
		if (weight > maxWeightMap.at("Letter"))
		{
			throw new PackageException(pack, "Package too heavy");
		}
	}
	else if (trNum.back() == '1')//box
	{
		pack = make_unique<Box>(trackNum, weight, pricePerLbMap.at("Box")*weight);
		if (weight > maxWeightMap.at("Box"))
		{
			throw new PackageException(pack, "Package too heavy");
		}
	}
	else if (trNum.back() == '2')//wooden crate
	{
		pack = make_unique<WoodCrate>(trackNum, weight, pricePerLbMap.at("Wood Crate")*weight);
		if (weight > maxWeightMap.at("Wood Crate"))
		{
			throw new PackageException(pack, "Package too heavy");
		}
	}
	else if (trNum.back() == '3')//metal crate
	{
		pack = make_unique<MetalCrate>(trackNum, weight, pricePerLbMap.at("Metal Crate")*weight);
		if (weight > maxWeightMap.at("Metal Crate"))
		{
			throw new PackageException(pack, "Package too heavy");
		}
	}
	else
	{
		throw new PackageException(pack, "Unkown Package");
	}
	return pack;
}
