#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class User
{
    string username;
    string password;
public:
    User(const string& ur, const string& pw);
    // Метод для входа в учетную запись
    bool login(const string& username, const string& password);

    // Метод для создания новой учетной записи
    bool createAccount(const string& username, const string& password);
};

