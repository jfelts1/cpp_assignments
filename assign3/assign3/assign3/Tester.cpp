/*
* James Felts
*
* Compilers Used
* Visual C++ 2015 x64 target
* g++ 4.9.2 using -std=c++14
*/

#include "FileUtils.h"
#include "PackageException.h"
#include "PackageFactory.h"
#include "Truck.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;

int main()
{
	ManifestHeader manifestHeader;
	vector<ManifestEntry> manifestBody;

	ifstream fin;
	openManifestFile(fin);
	if (fin.bad() || fin.fail())
	{
		return EXIT_FAILURE;
	}
	manifestHeader = readManifestHeader(fin);
	manifestBody = readManifestBody(fin);
	fin.close();

	Truck tr(manifestHeader);

	unique_ptr<Package> temp;
	for (ManifestEntry entry : manifestBody)
	{
		try
		{
			temp = packageFactory(entry);
			tr.loadTruck(temp);
		}
		catch (const PackageException& e)
		{
			log(string(e.what()) + "\nPackage: " + e.getNameOfPackage()+"\nTracking Number: "+to_string(e.getPackageTrackingNumber())+"\nWeight"+ to_string(e.getPackageWeight())+"\n");
		}
	}

	return 0;
}