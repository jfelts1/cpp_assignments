#include "PackageException.h"

PackageException::PackageException(std::unique_ptr<Package>& pack, const char * message):runtime_error(message)
{
	_packageName = pack->getName();
	_packageTrackingNumber = pack->getTrackingNumber();
	_packageWeight = pack->getWeight();
}

PackageException::PackageException(std::unique_ptr<Package>& pack, std::string message) :runtime_error(message.c_str())
{
	_packageName = pack->getName();
	_packageTrackingNumber = pack->getTrackingNumber();
	_packageWeight = pack->getWeight();
}

PackageException::PackageException(const char * message):runtime_error(message)
{
}

PackageException::PackageException(std::string message):runtime_error(message.c_str())
{
}

PackageException::PackageException(PackageException& packEx):runtime_error(packEx.what())
{
	_packageName = packEx.getNameOfPackage();
	_packageTrackingNumber = packEx.getPackageTrackingNumber();
	_packageWeight = packEx.getPackageWeight();
}
