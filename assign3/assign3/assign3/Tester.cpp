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
#include <array>
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


	/*for (string str : manifestHeader)
	{
		cout << str << "\n";
	}
	cout << endl;

	for (string str : manifestBody)
	{
		cout << str << "\n";
	}
	cout << endl;*/
	
	return 0;
}