#include "Constants.h"
#include "UI.h"
#include <iostream>

wstring_convert<codecvt_utf8<wchar_t>> converter;

void setLocale() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void setUTF8() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}

void printJSON(string toPrint = "") {
	setUTF8();
	std::cout << toPrint;
	setLocale();
}

void setTitle(wstring title) {
	SetConsoleTitleW((APP_NAME + title).c_str());
}

wstring to_wstring(string str) {
	return converter.from_bytes(str);
}