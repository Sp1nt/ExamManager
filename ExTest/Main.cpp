#include <iostream>
#include "User.h" 
#include "Disk.h" 
#include "Folder.h"
#include "File.h"
#include "FileSystem.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    setlocale(0, "");



    FileSystem* folder;
    FileSystem* file;
    User* currentUser;
    Disk* disk;
    bool isLoggedIn = false;

    size_t fileSize;
    string username;
    string password;


    string name;
    string path;
    string destinationPath;

    wstring pathh; 
    wstring mask;
    while (true) {
        if (!isLoggedIn) {
         
            cout << "1. Войти\n";
            cout << "2. Зарегистрироваться\n";
            cout << "3. Выйти из программы\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                // Логин
                cout << "Введите логин: ";
                cin >> username;
                cout << "Введите пароль: ";
                cin >> password;

                if (currentUser->login(username, password)) {
                    isLoggedIn = true;
                }
                else {
                    cout << "Ошибка входа. Неверное имя пользователя или пароль." << endl;
                }
            }
            else if (choice == 2) {
                // Регистрация
                cout << "Введите логин: ";
                cin >> username;
                cout << "Введите пароль: ";
                cin >> password;

                if (currentUser->createAccount(username, password)) {
                    cout << "Регистрация успешна." << endl;
                    isLoggedIn = true;
                }
                else {
                    cout << "Ошибка регистрации. Логин уже существует." << endl;
                }
            }
            else if (choice == 3) {
                // Выход из программы
                break;
            }
        }
        else {
            // Если пользователь вошел, предлагаем операции с файлами и папками
            cout << "1. Создать папку\n";
            cout << "2. Удалить папку\n";
            cout << "3. Переименовать папку\n";
            cout << "4. Переместить папку\n";

            cout << "|||||||||||||||||||||||||||" << endl;

            cout << "5. Создать файл\n";
            cout << "6. Удалить файл\n";
            cout << "7. Переименовать файл\n";
            cout << "8. Переместить файл\n";

            cout << "|||||||||||||||||||||||||||" << endl;

            cout << "9. Показать содержимое файла\n";
            cout << "10. Вписать что-то в файл\n";
            cout << "11. Вычислить размер файла\n";
            cout << "12. Выводим все файлы и папки\n";
            cout << "13. Поиск по маске\n";
            cout << "14. Выйти из аккаунта\n";
            cout << "15. Выйти из программы\n";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Создание папки > " << endl;
                cout << "Введите имя папки: ";
                cin >> name;

                folder->createEntity(name);

                break;
            case 2:
                cout << "Удаление папки > " << endl;
                cout << "Введите путь папки: ";
                cin >> path;

                folder->deleteEntity(path);

                break;
            case 3:
                cout << "Переименование папки > " << endl;
                cout << "Введите путь папки: ";
                cin >> path;

                cout << "Введите новое имя папки: ";
                cin >> name;

                folder->renameEntity(path, name);
                break;
            case 4:
                cout << "Перенос папки > " << endl;
                cout << "Введите путь папки: ";
                cin >> path;

                cout << "Введите новый путь папки: ";
                cin >> destinationPath;

                folder->moveEntity(path, destinationPath);
                break;
            case 5:
                cout << "Создание файла > " << endl;
                cout << "Введите имя файла: ";
                cin >> name;

                file->createEntity(name);
                break;
            case 6:
                cout << "Удаление файла > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;

                file->deleteEntity(path);
                break;
            case 7:
                cout << "Переименование файла > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;

                cout << "Введите новое имя файла: ";
                cin >> name;

                file->renameEntity(path, name);
                break;
            case 8:
                cout << "Перенос файла > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;

                cout << "Введите новый путь файла: ";
                cin >> destinationPath;

                file->renameEntity(path, destinationPath);
                break;
            case 9:
                cout << "Чтение файла > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;

                disk->readFromFile(path);
                break;
            case 10:
                cout << "Запись в файл > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;
                cin.ignore();
                cout << "Введите то что хотите ввести: ";
                getline(cin, destinationPath);

                disk->writeToFile(path, destinationPath);
                break;
            case 11:
                cout << "Показ размера файла > " << endl;
                cout << "Введите путь файла: ";
                cin >> path;
                cout << "\n" << endl;

                 fileSize = disk->getFileSize(path);
                cout << "Размер файла: " << fileSize << " байт" << endl;
                break;
            case 12:
                cout << "Показ всех файлов и директорий > " << endl;
                cout << "Введите путь папка: ";
                cin >> path;
                disk->listDirectory(path);
                break;
            case 13:
                cout << "Поиск по маске  \\ > " << endl;
                cout << "Введите путь: ";
                wcin >> pathh;

                cout << "Введите маску: ";
                wcin >> mask;

                disk->findFilesByMask(pathh, mask);
                break;
            case 14:
                isLoggedIn = false;
                break;
            case 15:
                cout << "Ваш код для удаления папки" << endl;
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        }
    }

    return 0;
}