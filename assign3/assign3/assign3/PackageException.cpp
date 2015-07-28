#include "PackageException.h"

PackageException::PackageException(std::unique_ptr<Package>& pack, const char * message):runtime_error(message)
{
	_packageName = pack->getName();
	_packageTrackingNumber = pack->getTrackingNumber();
	_packageWeight = pack->getWeight();
}

PackageException::PackageException(int trackNo, double weight,const char * message):runtime_error(message)
{
	_packageTrackingNumber = trackNo;
	_packageWeight = weight;
}

PackageException::PackageException(PackageException& packEx):runtime_error(packEx.what())
{
	_packageName = packEx.getNameOfPackage();
	_packageTrackingNumber = packEx.getPackageTrackingNumber();
	_packageWeight = packEx.getPackageWeight();
}
