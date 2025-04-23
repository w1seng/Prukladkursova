#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Seat {
public:
    bool seatStat[9][8]{};

    void seatStatus() {
        cout << "\t\t\tSEATS STATUS" << endl;
        cout << "___________________________________________________________________" << endl;
        cout << "|# |\t1\t2\t3\t4\t5\t6\t7\t8 |" << endl;
        cout << "|__|_______________________________________________________________|" << endl;
        for (int i = 0; i < 9; i++) {
            cout << "|" << i + 1 << " |";
            for (int j = 0; j < 8; j++) {
                if (seatStat[i][j] == 0) {
                    cout << "\tO";
                } else {
                    cout << "\tX";
                }
            }
            cout << " |" << endl;
        }
        cout << "|__|_______________________________________________________________|" << endl;
        cout << "Attention!!!\n If you choose rows 1-3 the price doesn't change\n Row 4-6 - price multiplies on 2 \n Row 7-9 - price multiplies on 3\n" << endl;
    }

    void saveSeat() {
        ofstream fout;
        fout.open("SeatStatus.txt");
        string templine;
        for (int i = 0; i < 9; i++) {
            templine = "";
            for (int j = 0; j < 8; j++) {
                templine += seatStat[i][j] + 48;
            }
            fout << templine << endl;
        }
        fout.close();
    }

    void readSeat() {
        ifstream fin;
        fin.open("SeatStatus.txt");
        string templine;
        int i = 0;
        while (!fin.eof()) {
            getline(fin, templine);
            if (templine.length() != 8) {
                continue;
            }
            for (int j = 0; j < 8; j++) {
                seatStat[i][j] = (int)templine[j] - 48;
            }
            i++;
        }
        fin.close();
    }
};
