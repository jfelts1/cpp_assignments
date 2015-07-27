#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <ctime>
#define BUFFERSIZE 100
#define MANIFEST_HEADER_SIZE 4

class ManifestHeader
{
public:
	ManifestHeader() {};
	ManifestHeader(std::array<std::string,MANIFEST_HEADER_SIZE> data);
	virtual ~ManifestHeader() {};
	std::string getDriverName()const { return _data[0]; }
	double getBaseWeight()const { return stod(_data[1]); }
	std::string getOriginCity()const { return _data[2]; }
	std::string getDestCity()const { return _data[3]; }

private:
	std::array<std::string, MANIFEST_HEADER_SIZE> _data;
};




std::ifstream& openManifestFile(std::ifstream& fin);
ManifestHeader readManifestHeader(std::ifstream&fin);
std::vector<std::string> readManifestBody(std::ifstream& fin);

std::ofstream& openLogFile(std::ofstream& fout);
void log(std::string message);

#endif