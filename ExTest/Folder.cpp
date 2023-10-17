#include "Folder.h"


Folder::Folder(const string& name, const string& path) : FileSystem(name, path) {}

bool Folder::createEntity(const string& name) {
	if (_mkdir(name.c_str()) == 0) {
		cout << "Folder created successfully." << endl;
		return true;
	}
	else {
		cout << "Error creating folder.." << endl;
		return false;
	}
}

bool Folder::deleteEntity(const string& path)
{
	if (_rmdir(path.c_str()) == 0) {
		cout << "Folder deleted successfully." << endl;
		return true;
	}
	else {
		cout << "Error deleting folder." << endl;
		return false;
	}
}

bool Folder::renameEntity(const string& path, const string& newName)
{
	
	if (rename(path.c_str(), newName.c_str()) == 0) {
		cout << "Folder renamed successfully." << endl;
		return true;
	}
	else {
		cout << "Error renaming folder." << endl;
		return false;
	}
}

bool Folder::moveEntity(const string& sourcePath, const string& destinationPath)
{
	if (rename(sourcePath.c_str(), destinationPath.c_str()) == 0) {
		cout << "Folder moved successfully." << endl;
		return true;
	}
	else {
		cout << "Error moving folder." << endl;
		return false;
	}
}

