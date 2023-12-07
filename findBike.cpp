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
        cout << "Введіть ваш варіант відповіді (від 1 до " << posibleChoices << "): ";
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
    // Вектор велосипедів
    vector<Bicycle> bicycles = {
      {"City-Bike"},
      {"Mountain Bike (MTB)"},
      {"Road Bike"},
    };

    // Запитання користувачу
    cout << "Для чого вам потрібен велосипед?\n"
        << "1. Поїздки по місту/шляхам.\n"
        << "2. Гірські або лісові маршрути.\n"
        << "3. Тренування і фітнес.\n";
    takeAnswer(3);

    cout << "Яка вага велосипеда для вас оптимальна?\n"
        << "1. Тяжкий (стабільний на великій швидкості або навантаженні).\n"
        << "2. Середня вага.\n"
        << "3. Легкий (зручний для переноски).\n";
    takeAnswer(3);

    cout << "Якою буде ваша середня відстань поїздки?\n"
        << "1. Короткі відстані (до 5 км).\n"
        << "2. Середні відстані (5-20 км).\n"
        << "3. Довгі відстані (понад 20 км).\n";
    takeAnswer(3);

    cout << "Яка ваша фізична підготовка?\n"
        << "1. Початківець.\n"
        << "2. Середній рівень підготовки.\n"
        << "3. Досвідчений райдер.\n";
    takeAnswer(3);

    cout << "Яка швидкість вам необхідна?\n"
        << "1. Бажаю повільної, але стабільної їзди.\n"
        << "2. Середня швидкість.\n"
        << "3. Максимальна швидкість.\n";
    takeAnswer(3);
     

    // Виведення результату
    cout << "Судячи по вашим вподобанням вам підійде " << type << "." << endl;
    _getch();
}
