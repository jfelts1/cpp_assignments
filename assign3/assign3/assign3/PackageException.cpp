#include "PackageException.h"

PackageException::PackageException(std::unique_ptr<Package>& pack, const char * message):exception()
{
	_message = message;
	_pack = move(pack);
}
