#include "Constants.h"
#include "UI.h"

void setLocale() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void setUTF8() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}
void setTitle(string title) {
	SetConsoleTitleA((APP_NAME + title).c_str());
}