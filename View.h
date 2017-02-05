#pragma once
#include "Header.h"

class View
{
public:
	static void demo()
	{
		cout << "Программа принимает математическое выражение, введенное пользователем, и вычисляет его.\n";
	}
	static void askExpression(string& str)
	{
		cout << "Введите выражение для анализа, после нажмите Enter: ";
		getline(cin, str);
	}
	static void result(int res, const string& str)
	{
		system("cls");
		cout << str << " = " << res;
	}
	

};

