#include "FileManager.h"
#include "askHeight.h"
#include "findBike.h"
#include "UI.h"
using namespace std;

vector<Option>& vectorOfOptions = getVectorOfOptions();

// Просимо користувача обрати опцію з можливих
size_t getInput(string question) {
	size_t choice = 0;
	do {
		printf(question.c_str());
		scanf_s("%d", &choice);
	} while ((choice < 1 && choice != 0) || choice > vectorOfOptions.size());
	return choice;
}

void showMenu() {
	system("cls");
	setTitle(L"Головне меню");

	// Код головного меню
	printf("Вітаємо, ви знаходитесь в меню велодовідника.\n");
	printf("Оберіть один з пунктів про який ви хочете дізнатися більше:\n");
	getOptions();

	// Вибір пункту
	size_t optionsSize = vectorOfOptions.size();
	string question = "\nВаш вибір (Введіть цифру від 1 до " + to_string(optionsSize) + ",\n0 - щоб вийти з програми): ";
	size_t choice = getInput(question);
	if (choice == 0) return;

	// Наступний крок	
	// Задаємо заголовок
	wstring wideString = to_wstring(vectorOfOptions[choice - 1].name);
	setTitle(wideString);

	// Працюємо з наступним файлом
	system("cls");
	wstring path = to_wstring(vectorOfOptions[choice - 1].path), askFrameSize = L"askFrameSize", askFindBike = L"findBike";
	if (path == askFrameSize) {
		discoverFrameSize();
	}
	else if (path == askFindBike) {
		discoverBikes();
	}

	ifstream f(path);
	checkFile(f);

	setUTF8();
	// Виводимо інформацію
	string line;
	while (getline(f, line)) {
		printf("%s\n", line.c_str());
	}
	setLocale();
	f.close();

	printf("\nНатисніть будь яку клавішу аби потрапити на головне меню...");
	_getch();
	showMenu();
}

int main()
{
	setLocale();
	showMenu();

	printf("\nДо зустрічі!");

	//clearVector();
	//delete[] vectorOfOptions.data();
}
