#pragma once
#include "Seat.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class Login {
protected:
    string password, userName;

public:
    void login() {
        char c;
        map<string, string> mp;
        ifstream loginSign("LoginSign.txt");
        string templine;

        while (getline(loginSign, templine)) {
            cout << "\t" << templine << endl;
            Sleep(25);
        }
        loginSign.close();

        userName = "";
        password = "";
        mp["admin"] = "pass";

        cout << "Enter the login:" << endl;
        cin >> userName;
        cout << "Enter the password:" << endl;

        while ((c = _getch()) != '\r') {
            if (c == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
                continue;
            }
            password.push_back(c);
            _putch('*');
        }

        if (mp.count(userName) == 1 && mp[userName] == password) {
            cout << "\nAccess is successful" << endl;
            Sleep(3000);
            system("cls");
        } else {
            cout << "\nThe user name or password is wrong. Access denied!" << endl;
            Sleep(3000);
            system("cls");
            login();
        }
    }
};

void showRulesOfConduct() {
    system("cls");
    ifstream rulesRead("RulesOfConduct.txt");
    string templine;

    while (getline(rulesRead, templine)) {
        cout << templine << endl;
        Sleep(25);
    }
    rulesRead.close();
    system("pause");
}

void showListOfFoodAndDrinks() {
    system("cls");
    ifstream listRead("ListOfFoodAndDrinks.txt");
    string templine;

    while (getline(listRead, templine)) {
        cout << templine << endl;
        Sleep(25);
    }
    listRead.close();
    system("pause");
}
