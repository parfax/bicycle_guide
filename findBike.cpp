#include "findBike.h"

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int maxi = 0;
string type;

class Bicycle {
public:
    string type;

    Bicycle(string t) : type(t) {}
};

int road = 0, mtb = 0, city = 0;

void takeAnswer(int posibleChoices) {
    int choice;
    do {
        cout << "������ ��� ������ ������ (�� 1 �� " << posibleChoices << "): ";
        cin >> choice;

        if (choice <= posibleChoices) {
            switch (choice) {
            case 1:
                city++;
                break;
            case 2:
                mtb++;
                break;
            case 3:
                road++;
                break;
            }
        }
    } while (choice < 1 || choice > posibleChoices);

    if (city > maxi) {
        maxi = city; type = "City-Bike";
    }
    else if (mtb > maxi) {
        maxi = mtb; type = "Mountain Bike (MTB)";
    }
    else if (road > maxi) {
        maxi = road;
        type = "Road Bike";
    }
}

void discoverBikes() {
    system("cls");
    // ������ ����������
    vector<Bicycle> bicycles = {
      {"City-Bike"},
      {"Mountain Bike (MTB)"},
      {"Road Bike"},
    };

    // ��������� �����������
    cout << "��� ���� ��� ������� ���������?\n"
        << "1. ������ �� ����/������.\n"
        << "2. ó���� ��� ���� ��������.\n"
        << "3. ���������� � ������.\n";
    takeAnswer(3);

    cout << "��� ���� ���������� ��� ��� ����������?\n"
        << "1. ������ (��������� �� ������ �������� ��� �����������).\n"
        << "2. ������� ����.\n"
        << "3. ������ (������� ��� ���������).\n";
    takeAnswer(3);

    cout << "���� ���� ���� ������� ������� ������?\n"
        << "1. ������ ������ (�� 5 ��).\n"
        << "2. ������ ������ (5-20 ��).\n"
        << "3. ���� ������ (����� 20 ��).\n";
    takeAnswer(3);

    cout << "��� ���� ������� ���������?\n"
        << "1. ����������.\n"
        << "2. ������� ����� ���������.\n"
        << "3. ���������� ������.\n";
    takeAnswer(3);

    cout << "��� �������� ��� ���������?\n"
        << "1. ����� �������, ��� �������� ����.\n"
        << "2. ������� ��������.\n"
        << "3. ����������� ��������.\n";
    takeAnswer(3);
     

    // ��������� ����������
    cout << "������ �� ����� ����������� ��� ����� " << type << "." << endl;
    _getch();
}
