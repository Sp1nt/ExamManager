#pragma once
#include "FileSystem.h"

class File :
    public FileSystem
{
public:
    File(const string& name, const string& path);
    bool createEntity(const string& name);
    bool deleteEntity(const string& path);
    bool renameEntity(const string& path, const string& newName);
    bool moveEntity(const string& sourcePath, const string& destinationPath);
};

