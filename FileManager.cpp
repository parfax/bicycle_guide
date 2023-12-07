#include "FileManager.h"
#include "UI.h"

vector<Option> options;
ordered_json jsonFile;
vector<Option>& getVectorOfOptions() { return options; }

// Перевіряємо чи існує файл, інакше виводимо помилку
void checkFile(ifstream& f) {
	if (!f.is_open()) {
		system("cls");
		cerr << "Помилка: перевірте цілісність файлів програми.\n";
	}
}

void initVectorOfOptions() {
	ifstream f("Materials/Main Menu/options.json");
	checkFile(f);

	f >> jsonFile;

	// Ініціалізуємо масив опцій
	Option option;
	for (auto& element : jsonFile.items()) {
		option.name = element.key(); // Назва опції
		option.path = element.value(); // Шлях до наступного файлу

		options.push_back(option);
	}
	f.close();
}

void getOptions() {
	// Не потрібно проводити одні й ті ж процедури, якщо вектор вже був ініціалізований.
	if (options.size() == 0) initVectorOfOptions();

	// Виводимо доступні опції
	setUTF8();
	for (size_t i = 0; i < options.size(); i++)
		printf("%d. %s\n", i + 1, options[i].name.c_str());
	setLocale();	
}

void clearVector() {
	delete[] options.data();
	jsonFile.clear();
}