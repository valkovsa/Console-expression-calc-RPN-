#pragma once
#include "Header.h"

class View
{
public:
	static void demo()
	{
		cout << "��������� ��������� �������������� ���������, ��������� �������������, � ��������� ���.\n";
	}
	static void askExpression(string& str)
	{
		cout << "������� ��������� ��� �������, ����� ������� Enter: ";
		getline(cin, str);
	}
	static void result(int res, const string& str)
	{
		system("cls");
		cout << str << " = " << res;
	}
	

};

