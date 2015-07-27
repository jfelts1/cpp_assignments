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
		
	}
	else if (trNum.back() == '1')//box
	{

	}
	else if (trNum.back() == '2')//wooden crate
	{

	}
	else if (trNum.back() == '3')//metal crate
	{

	}
	else
	{
		throw new PackageException(pack, "Unkown Package");
	}
	return pack;
}
