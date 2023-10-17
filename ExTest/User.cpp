#include "User.h"


User::User(const string& ur, const string& pw) : username(ur), password(pw) {}

bool User::login(const string& username, const string& password) {
    ifstream file("password.txt");
    if (!file.is_open()) {
        cout << "Error opening file 'password.txt'." << endl;
        return false;
    }

    string userLine;
    while (getline(file, userLine)) {
        size_t separatorPos = userLine.find(" | ");
        if (separatorPos != string::npos) {
            string storedUsername = userLine.substr(0, separatorPos);
            string storedPassword = userLine.substr(separatorPos + 3); // Учитываем пробел и разделитель

            if (storedUsername == username && storedPassword == password) {
                file.close(); // Закрыть файл после успешного входа
                return true;
            }
        }
    }

    file.close(); // Закрыть файл после завершения поиска

    return false;
}


bool User::createAccount(const string& username, const string& password) {
    fstream file("password.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Error opening file 'password.txt'." << endl;
        return false;
    }

    string userLine;
    bool usernameExists = false;

    while (getline(file, userLine)) {
        size_t separatorPos = userLine.find(" | ");
        if (separatorPos != string::npos) {
            string storedUsername = userLine.substr(0, separatorPos);

            if (storedUsername == username) {
                usernameExists = true;
                break;
            }
        }
    }

    if (!usernameExists) {
        file.clear();
        file.seekp(0, ios::end);  // Перейти в конец файла для добавления новой записи.
        file << username << " | " << password << "\n";
        file.close();


        return true;
    }
    else {
        file.close();
        return false;
    }
}







void User::logout() {
    cout << "ff";
}
