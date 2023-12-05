#include "FileManager.h"
#include "UI.h"

vector<Option> options;

vector<Option>& getVectorOfOptions() { return options; }

// ���������� �� ���� ����, ������ �������� �������
void checkFile(ifstream& f) {
	if (!f.is_open()) {
		system("cls");
		cerr << "�������: �������� �������� ����� ��������.\n";
	}
}

void getOptions() {
	// �������� ������� ����
	ifstream f("Materials/Main Menu/options.json");
	checkFile(f);

	ordered_json jsonFile;
	f >> jsonFile;

	// ���������� ����� �����
	Option option;
	for (auto& element : jsonFile.items()) {
		option.name = element.key(); // ����� �����
		option.path = element.value(); // ���� �� ���������� �����

		options.push_back(option);
	}

	// �������� ������� �����
	setUTF8();
	for (size_t i = 0; i < options.size(); i++)
		printf("%d. %s\n", i + 1, options[i].name.c_str());
	setLocale();

	f.close();
}