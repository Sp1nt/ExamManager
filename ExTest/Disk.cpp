#include "Disk.h"

Disk::Disk(const string& path) : path(path)
{
}

void Disk::readFromFile(const string& path) {
    ifstream file(path);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error: The file cannot be opened " << path << endl;
    }
}

bool Disk::writeToFile(const string& path, const string& content)
{
    ofstream file(path, ios::out);
    if (file.is_open()) 
    {
        file << content;
        file.close();
        return true;
    }
    else {
        cout << "Error: Unable to write to file " << path << endl;
        return false;
    }
}

size_t Disk::getFileSize(const string& path) const
{
    ifstream file(path, ios::binary | ios::ate);
    if (file.is_open())
    {
        size_t size = file.tellg();
        file.close();
        return size;
    }
    else 
    {
        cout << "Error: File " << path << " does not exist or is not a regular file." << endl;
        return 0;
    }
}


void Disk::listDirectory(const string& path) const {
    struct _finddata_t   fileInfo; //��� �������� ���������� � ��������� ������ � ������.
    intptr_t handle; //������������� ����������, ��� ������������ ��������� ������

    string searchPattern = path + "\*.*";//������ ������,�������� � ���� ��������� ���� � "\*.*"��������, ��� �� ���� ��� ����� � ����� � ������ ����������.

    // ���� ����� � ����� � ��������� ����������.
    if ((handle = _findfirst(searchPattern.c_str(), &fileInfo)) != -1) {
        do {
            string filename = fileInfo.name;
            // �� ������ �������� ����� ��������� ��������� ������ � �����, ��������, �� �����.
            cout << filename << endl;
        } while (_findnext(handle, &fileInfo) == 0);

        _findclose(handle);
    }
    else {
        cout << "Error when searching for files and folders in a directory " << path << endl;
    }
}


void Disk::findFilesByMask(const wstring& path, const wstring& mask)
{
    WIN32_FIND_DATAW findFileData; // �������� �������� �� 'W' � �������� ���������
    HANDLE hFind = FindFirstFileW((path + L"\\*").c_str(), &findFileData); // ���������� 'W' ������ ������� � 'L' ����� ��������

    if (hFind == INVALID_HANDLE_VALUE) {
        return; // ����� �� ��������, ���� ��� ������ � ������� �����
    }

    do {
        const wstring fileName = findFileData.cFileName;

        if (fileName != L"." && fileName != L"..") { // ��������� . � .. �� ������
            const wstring filePath = path + L"\\" + fileName;

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // ��� �����, ���������� �������� ������� ��� ������ � ��������
                findFilesByMask(filePath, mask);
            }
            else {
                // ��� ����, ��������� ��� ��� �� �����
                if (PathMatchSpecW(fileName.c_str(), mask.c_str())) {
                    wcout << L"File: " << filePath << endl;
                }
            }
        }
    } while (FindNextFileW(hFind, &findFileData) != 0); // ���������� 'W' ������ �������

    FindClose(hFind);
}