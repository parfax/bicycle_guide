#include "askHeight.h"
#include <conio.h>

string getFrameSize() {
	string size;
    short unsigned height;    

	cout << "������ ��� ���� � �� (�� 130 �� 210): ";
	cin >> height;

    if (height >= 130 && height <= 144) 
        size = "XS";
    
    else if (height >= 145 && height <= 155) 
        size = "S";
    
    else if (height >= 156 && height <= 169) 
        size = "M";
    
    else if (height >= 170 && height <= 179) 
        size = "L";
    
    else if (height >= 180 && height <= 189) 
        size = "XL";
    
    else if (height >= 190 && height <= 210) 
        size = "XXL";
    
    else size = "�������� �����";

	return size;
}

void discoverFrameSize() {
    cout << "��� �������� ����� ������ ��������� ��� �����\n";
    string frameSize = getFrameSize();
    cout << "\n��� ��� ������ ��������� � ����� ������� ����: " << frameSize;
    _getch();
}