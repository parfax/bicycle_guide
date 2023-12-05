#include "FileManager.h"
#include "UI.h"
using namespace std;

vector<Option>& vectorOfOptions = getVectorOfOptions();

// Просимо користувача обрати опцію з можливих
size_t getInput(string question) {
	size_t choice = 0;
	do {
		printf(question.c_str());
		scanf_s("%d", &choice);
	} while (choice < 1 || choice > vectorOfOptions.size());
	return choice;
}

int main()
{
	setLocale();
	setTitle("Головне меню");

	// Код головного меню
	printf("Вітаємо, ви знаходитесь в меню велодовідника.\n");
	printf("Оберіть один з пунктів про який ви хочете дізнатися більше:\n");
	getOptions();

	// Вибір пункту
	size_t optionsSize = vectorOfOptions.size();
	string question = "Ваш вибір (від 1 до " + to_string(optionsSize) + "): ";
	size_t choice = getInput(question);
	
	// Наступний крок
	//setUTF8();
	setTitle(vectorOfOptions[choice - 1].name);
	//setLocale();
	system("cls");
	ifstream f(vectorOfOptions[choice - 1].path);
	checkFile(f);

	string line;
	setUTF8();
	while (getline(f, line)) {
		printf("%s\n", line.c_str());
	}
	setLocale();

	f.close();

	_getch();
}
