#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <io.h>
#include <shlwapi.h>
#include <windows.h>
#include <vector>

#pragma comment(lib, "shlwapi.lib")

using namespace std;

class Disk
{
    string path;
  
public:
    Disk(const string& path);
    void readFromFile(const string& path);
    bool writeToFile(const string& path, const string& content);
    size_t getFileSize(const string& path) const;
    void listDirectory(const string& path) const;
    void findFilesByMask(const wstring& path, const wstring& mask);
};

