#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <direct.h>


using namespace std;

class FileSystem
{
protected:
    string name;
    string path;
public:
    FileSystem() : name(""), path("") {};
    FileSystem(const string& name, const string& path) : name(name), path(path) {}
    virtual bool createEntity(const string& name) = 0;
    virtual bool deleteEntity(const string& path) = 0;
    virtual bool renameEntity(const string& path, const string& newName) = 0;
    virtual bool moveEntity(const string& sourcePath, const string& destinationPath) = 0;
    
};

