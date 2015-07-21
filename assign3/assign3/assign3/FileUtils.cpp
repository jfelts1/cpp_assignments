#include "FileUtils.h"
using namespace std;

const string manifestFileName = "manifest.txt";
const string logFileName = "log.txt";

ifstream& openManifestFile(ifstream& fin)
{
	fin.open(manifestFileName);
	if (!fin.is_open())
	{
		fin.clear();
		fin.close();
		cerr << "error " << manifestFileName << " not found." << endl;
	}

	return fin;
}

std::array<std::string, MANIFEST_HEADER_SIZE> readManifestHeader(std::ifstream& fin)
{
	array<string, MANIFEST_HEADER_SIZE> out;
	char buf[BUFFERSIZE]="";
	int i = 0;
	for (i = 0;i < MANIFEST_HEADER_SIZE;i++)
	{
		fin.getline(&buf[0], BUFFERSIZE);
		out[i] = buf;
		memset(buf, 0, BUFFERSIZE);
	}

	return out;
}

std::vector<std::string> readManifestBody(std::ifstream & fin)
{
	vector<string> out;
	char buf[BUFFERSIZE] = "";
	while (!fin.eof())
	{
		fin.getline(&buf[0], BUFFERSIZE);
		out.push_back(buf);
		memset(buf, 0, BUFFERSIZE);
	}

	return out;
}

std::ofstream& openLogFile(ofstream& fout)
{
	fout.open(logFileName,ios_base::app);
	if (!fout.is_open())
	{
		fout.clear();
		fout.close();
		fout.open(logFileName, ios_base::out);
	}

	return fout;
}

void log(std::string message)
{
	ofstream fout;
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
	fout << message << endl;
	fout.close();
}
