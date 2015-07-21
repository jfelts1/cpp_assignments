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

std::ifstream& openManifestFile(std::ifstream& fin);
std::array<std::string, MANIFEST_HEADER_SIZE> readManifestHeader(std::ifstream&fin);
std::vector<std::string> readManifestBody(std::ifstream& fin);

std::ofstream& openLogFile(std::ofstream& fout);
void log(std::string message);

#endif