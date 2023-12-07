#include <string>
#include <conio.h>
#include <windows.h>
#include <codecvt>
using namespace std;

void setUTF8();
void printJSON(string str);
void setLocale();
void setTitle(wstring title);

wstring to_wstring(string str);