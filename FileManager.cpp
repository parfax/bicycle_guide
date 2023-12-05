#include "FileManager.h"
#include "UI.h"

vector<Option> options;

vector<Option>& getVectorOfOptions() { return options; }

// Перевіряємо чи існує файл, інакше виводимо помилку
void checkFile(ifstream& f) {
	if (!f.is_open()) {
		system("cls");
		cerr << "Помилка: перевірте цілісність файлів програми.\n";
	}
}

void getOptions() {
	// Спробуємо відкрити файл
	ifstream f("Materials/Main Menu/options.json");
	checkFile(f);

	ordered_json jsonFile;
	f >> jsonFile;

	// Ініціалізуємо масив опцій
	Option option;
	for (auto& element : jsonFile.items()) {
		option.name = element.key(); // Назва опції
		option.path = element.value(); // Шлях до наступного файлу

		options.push_back(option);
	}

	// Виводимо доступні опції
	setUTF8();
	for (size_t i = 0; i < options.size(); i++)
		printf("%d. %s\n", i + 1, options[i].name.c_str());
	setLocale();

	f.close();
}