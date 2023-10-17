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
    struct _finddata_t   fileInfo; //для хранения информации о найденных файлах и папках.
    intptr_t handle; //целочисленная переменная, для отслеживания состояния поиска

    string searchPattern = path + "\*.*";//шаблон поиска,включает в себя указанный путь и "\*.*"означает, что мы ищем все файлы и папки в данной директории.

    // Ищем файлы и папки в указанной директории.
    if ((handle = _findfirst(searchPattern.c_str(), &fileInfo)) != -1) {
        do {
            string filename = fileInfo.name;
            // Вы можете добавить здесь обработку найденных файлов и папок, например, их вывод.
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
    WIN32_FIND_DATAW findFileData; // Обратите внимание на 'W' в названии структуры
    HANDLE hFind = FindFirstFileW((path + L"\\*").c_str(), &findFileData); // Используем 'W' версии функции и 'L' перед строками

    if (hFind == INVALID_HANDLE_VALUE) {
        return; // Выход из рекурсии, если нет файлов в текущей папке
    }

    do {
        const wstring fileName = findFileData.cFileName;

        if (fileName != L"." && fileName != L"..") { // Исключаем . и .. из поиска
            const wstring filePath = path + L"\\" + fileName;

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // Это папка, рекурсивно вызываем функцию для поиска в подпапке
                findFilesByMask(filePath, mask);
            }
            else {
                // Это файл, проверяем его имя по маске
                if (PathMatchSpecW(fileName.c_str(), mask.c_str())) {
                    wcout << L"File: " << filePath << endl;
                }
            }
        }
    } while (FindNextFileW(hFind, &findFileData) != 0); // Используем 'W' версии функции

    FindClose(hFind);
}