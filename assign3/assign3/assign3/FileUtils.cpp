#include "FileUtils.h"
using namespace std;

const string manifestFileName = "manifest.txt";

string loadManifestFile()
{
	ifstream fin;
	fin.open(manifestFileName);
	if (!fin.is_open())
	{
		fin.clear();
		fin.close();
		cerr << "error " << manifestFileName << " not found." << endl;
	}
	string out;
	char buf[BUFFERSIZE];
	while (!fin.eof())
	{
		fin.getline(&buf[0], BUFFERSIZE);
		out.append(buf);
		out.push_back('\n');
		memset(buf, 0, BUFFERSIZE);//zero out the buffer to ensure there is no leftover characters for the next iteration
	}

	return out;
}
