#pragma once
#include "Header.h"

class Controller
{
private:
	Parser* p;
	string str;

public:

	Controller()
	{
		p = new Parser;
	}
	~Controller()
	{
		delete p;
	}

	void start()
	{
		View::demo();
		View::askExpression(str);
		View::result(p->calc(str), str);
		

		//cout << str << " = " << p->calc(str);
	}


};

