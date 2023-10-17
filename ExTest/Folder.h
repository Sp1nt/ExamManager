#pragma once
#include "FileSystem.h"

class Folder :
    public FileSystem
{
public:
    Folder(const string& name, const string& path);
    bool createEntity(const string& name);
    bool deleteEntity(const string& path);
    bool renameEntity(const string& path, const string& newName);
    bool moveEntity(const string& sourcePath, const string& destinationPath);


};