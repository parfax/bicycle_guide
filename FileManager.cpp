#include "FileManager.h"
#include "UI.h"

vector<Option> options;
ordered_json jsonFile;
vector<Option>& getVectorOfOptions() { return options; }

// ���������� �� ���� ����, ������ �������� �������
void checkFile(ifstream& f) {
	if (!f.is_open()) {
		system("cls");
		cerr << "�������: �������� �������� ����� ��������.\n";
	}
}

void initVectorOfOptions() {
	ifstream f("Materials/Main Menu/options.json");
	checkFile(f);

	f >> jsonFile;

	// ���������� ����� �����
	Option option;
	for (auto& element : jsonFile.items()) {
		option.name = element.key(); // ����� �����
		option.path = element.value(); // ���� �� ���������� �����

		options.push_back(option);
	}
	f.close();
}

void getOptions() {
	// �� ������� ��������� ��� � � � ���������, ���� ������ ��� ��� �������������.
	if (options.size() == 0) initVectorOfOptions();

	// �������� ������� �����
	setUTF8();
	for (size_t i = 0; i < options.size(); i++)
		printf("%d. %s\n", i + 1, options[i].name.c_str());
	setLocale();	
}

void clearVector() {
	delete[] options.data();
	jsonFile.clear();
}