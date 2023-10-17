#include "File.h"


File::File(const string& name, const string& path) : FileSystem(name, path) {}

bool File::createEntity(const string& name)
{
    string entityPath = name;
    ofstream newFile(entityPath);
    return newFile.is_open();
}

bool File::deleteEntity(const string& path)
{
    if (remove(path.c_str()) == 0) {
        cout << "File deleted successfully." << endl;
        return true;
    }
    else {
        cout << "Error deleting file." << endl;
        return false;
    }
}

bool File::renameEntity(const string& path, const string& newName)
{
    if (rename(path.c_str(), newName.c_str()) == 0) {
        cout << "File renamed successfully." << endl;
        return true;
    }
    else {
        cout << "Error renaming file." << endl;
        return false;
    }
}

bool File::moveEntity(const string& sourcePath, const string& destinationPath)
{

        if (rename(sourcePath.c_str(), destinationPath.c_str()) == 0) {
            cout << "File moved successfully." << endl;
            return true;
        }
        else {
            cout << "Error moving file." << endl;
            return false;
        }
}