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
         
            cout << "1. �����\n";
            cout << "2. ������������������\n";
            cout << "3. ����� �� ���������\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                // �����
                cout << "������� �����: ";
                cin >> username;
                cout << "������� ������: ";
                cin >> password;

                if (currentUser->login(username, password)) {
                    isLoggedIn = true;
                }
                else {
                    cout << "������ �����. �������� ��� ������������ ��� ������." << endl;
                }
            }
            else if (choice == 2) {
                // �����������
                cout << "������� �����: ";
                cin >> username;
                cout << "������� ������: ";
                cin >> password;

                if (currentUser->createAccount(username, password)) {
                    cout << "����������� �������." << endl;
                    isLoggedIn = true;
                }
                else {
                    cout << "������ �����������. ����� ��� ����������." << endl;
                }
            }
            else if (choice == 3) {
                // ����� �� ���������
                break;
            }
        }
        else {
            // ���� ������������ �����, ���������� �������� � ������� � �������
            cout << "1. ������� �����\n";
            cout << "2. ������� �����\n";
            cout << "3. ������������� �����\n";
            cout << "4. ����������� �����\n";

            cout << "|||||||||||||||||||||||||||" << endl;

            cout << "5. ������� ����\n";
            cout << "6. ������� ����\n";
            cout << "7. ������������� ����\n";
            cout << "8. ����������� ����\n";

            cout << "|||||||||||||||||||||||||||" << endl;

            cout << "9. �������� ���������� �����\n";
            cout << "10. ������� ���-�� � ����\n";
            cout << "11. ��������� ������ �����\n";
            cout << "12. ������� ��� ����� � �����\n";
            cout << "13. ����� �� �����\n";
            cout << "14. ����� �� ��������\n";
            cout << "15. ����� �� ���������\n";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "�������� ����� > " << endl;
                cout << "������� ��� �����: ";
                cin >> name;

                folder->createEntity(name);

                break;
            case 2:
                cout << "�������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                folder->deleteEntity(path);

                break;
            case 3:
                cout << "�������������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                cout << "������� ����� ��� �����: ";
                cin >> name;

                folder->renameEntity(path, name);
                break;
            case 4:
                cout << "������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                cout << "������� ����� ���� �����: ";
                cin >> destinationPath;

                folder->moveEntity(path, destinationPath);
                break;
            case 5:
                cout << "�������� ����� > " << endl;
                cout << "������� ��� �����: ";
                cin >> name;

                file->createEntity(name);
                break;
            case 6:
                cout << "�������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                file->deleteEntity(path);
                break;
            case 7:
                cout << "�������������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                cout << "������� ����� ��� �����: ";
                cin >> name;

                file->renameEntity(path, name);
                break;
            case 8:
                cout << "������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                cout << "������� ����� ���� �����: ";
                cin >> destinationPath;

                file->renameEntity(path, destinationPath);
                break;
            case 9:
                cout << "������ ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;

                disk->readFromFile(path);
                break;
            case 10:
                cout << "������ � ���� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;
                cin.ignore();
                cout << "������� �� ��� ������ ������: ";
                getline(cin, destinationPath);

                disk->writeToFile(path, destinationPath);
                break;
            case 11:
                cout << "����� ������� ����� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;
                cout << "\n" << endl;

                 fileSize = disk->getFileSize(path);
                cout << "������ �����: " << fileSize << " ����" << endl;
                break;
            case 12:
                cout << "����� ���� ������ � ���������� > " << endl;
                cout << "������� ���� �����: ";
                cin >> path;
                disk->listDirectory(path);
                break;
            case 13:
                cout << "����� �� �����  \\ > " << endl;
                cout << "������� ����: ";
                wcin >> pathh;

                cout << "������� �����: ";
                wcin >> mask;

                disk->findFilesByMask(pathh, mask);
                break;
            case 14:
                isLoggedIn = false;
                break;
            case 15:
                cout << "��� ��� ��� �������� �����" << endl;
                return 0;
            default:
                cout << "�������� �����. ���������� �����." << endl;
            }
        }
    }

    return 0;
}