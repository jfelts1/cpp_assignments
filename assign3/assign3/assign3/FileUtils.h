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
#define MANIFEST_HEADER_SIZE 5
#define MANIFEST_ENTRY_SIZE 2

class ManifestHeader
{
public:
	ManifestHeader() {}
	ManifestHeader(std::array<std::string, MANIFEST_HEADER_SIZE> data)
	{
		_data = data;
	}
	virtual ~ManifestHeader() {}
	std::string getDriverName()const { return _data[0]; }
	double getBaseWeight()const { return std::stod(_data[1]); }
	std::string getOriginCity()const { return _data[2]; }
	std::string getDestCity()const { return _data[3]; }

private:
	std::array<std::string, MANIFEST_HEADER_SIZE> _data;
};

class ManifestEntry
{
public:
	ManifestEntry() {}
	ManifestEntry(std::array<std::string, MANIFEST_ENTRY_SIZE> data)
	{
		_data = data;
	}
	virtual ~ManifestEntry() {}
	double getEntryWeight()const { return std::stod(_data[0]); }
	int getEntryTrackingNumber()const { return std::stoi(_data[1]); }
	std::string getEntryTrackingNumberString()const { return _data[1]; }
private:
	std::array<std::string, MANIFEST_ENTRY_SIZE> _data;
};


const std::string manifestFileName = "manifest.txt";
const std::string logFileName = "log.txt";

inline std::ifstream& openManifestFile(std::ifstream& fin)
{
	fin.open(manifestFileName);
	if (!fin.is_open())
	{
		fin.clear();
		fin.close();
		std::cerr << "error " << manifestFileName << " not found." << std::endl;
	}

	return fin;
}
inline ManifestHeader readManifestHeader(std::ifstream&fin)
{
	std::array<std::string, MANIFEST_HEADER_SIZE> out;
	char buf[BUFFERSIZE] = "";
	int i = 0;
	for (i = 0;i < MANIFEST_HEADER_SIZE;i++)
	{
		fin.getline(&buf[0], BUFFERSIZE);
		out[i] = buf;
		memset(buf, 0, BUFFERSIZE);
	}

	return ManifestHeader(out);
}
inline std::vector<ManifestEntry> readManifestBody(std::ifstream& fin)
{
	std::vector<ManifestEntry> out;
	char buf[BUFFERSIZE] = "";
	char buf2[BUFFERSIZE] = "";
	while (!fin.eof())
	{
		fin.getline(&buf[0], BUFFERSIZE);
		fin.getline(&buf2[0], BUFFERSIZE);
		out.push_back(ManifestEntry(std::array < std::string, MANIFEST_ENTRY_SIZE >() = { buf2, buf }));
		memset(buf, 0, BUFFERSIZE);
		memset(buf2, 0, BUFFERSIZE);
	}

	return out;
}

inline std::ofstream& openLogFile(std::ofstream& fout)
{
	fout.open(logFileName, std::ios_base::app);
	if (!fout.is_open())
	{
		fout.clear();
		fout.close();
		fout.open(logFileName, std::ios_base::out);
	}

	return fout;
}
inline  void log(std::string message)
{
	std::ofstream fout;
	openLogFile(fout);
	char buf[BUFFERSIZE] = "";
	struct tm newTime;
	//apprantly there is no safe time handling standard in C or C++
#ifdef _WIN32
	__int64 ltime;
	_time64(&ltime);
	_gmtime64_s(&newTime, &ltime);
	asctime_s(buf, BUFFERSIZE, &newTime);
#else
	time_t ltime;
	time(&ltime);
	asctime_r(gmtime_r(&ltime, &newTime), buf);
#endif
	/*//removing a newline that is ugly
	char* nl = strrchr(buf, '\n');
	*nl = '\0';*/

	fout << buf;
	fout << message << std::endl;
	fout.close();
}

#endif
