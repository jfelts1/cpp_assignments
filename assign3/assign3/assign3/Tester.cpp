/*
* James Felts
*/

#include "FileUtils.h"
#include "PackageException.h"
#include "PackageFactory.h"
#include "Truck.h"
using namespace std;


int main()
{
	string s;

	s = loadManifestFile();
	cout << s << endl;
	return 0;
}