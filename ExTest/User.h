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
    // ����� ��� ����� � ������� ������
    bool login(const string& username, const string& password);

    // ����� ��� �������� ����� ������� ������
    bool createAccount(const string& username, const string& password);
};

