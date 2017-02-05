#pragma once
#include "Header.h"

class Parser
{
private:
	bool delim(char c)
	{
		if (c == ' ')
			return true;
		else
			return false;
	}

	bool is_op(char c)
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			return true;
		else
			return false;
	}

	int priority(char op)
	{
		if (op == '+' || op == '-')
			return 1;
		else if (op == '*' || op == '/' || op == '%')
			return 2;
		else
			return -1;
	}

	void process_op(stack<int>& st, char op)
	{
		int r = st.top(); // Правый операнд
		st.pop();

		int l = st.top(); // Левый операнд
		st.pop();

		switch (op)
		{
		case '+':
			st.push(l + r);
			break;
		case '-':
			st.push(l - r);
			break;
		case '*':
			st.push(l * r);
			break;
		case '/':
			st.push(l / r);
			break;
		case '%':
			st.push(l % r);
			break;
		}
	}

public:
	Parser()
	{
	}

	int calc(string& s)
	{
		stack<int> st; // Стек с операндами
		stack<char> op; // Стек с операторами
		for (int i = 0; i < s.length(); ++i)
		{
			if (!delim(s[i]))
			{
				if (s[i] == '(')
					op.push('(');
				else if (s[i] == ')') // Если найдена закрывающая скобка, просматриваем выражение до открывающей скобки
				{
					while (op.top() != '(')
					{
						process_op(st, op.top());
						op.pop();
					}
					op.pop(); // Убираем открывающую скобку
				}
				else if (is_op(s[i])) // Если найден оператор
				{
					char curop = s[i];
					while (!op.empty() && priority(op.top()) >= priority(s[i])) // Если приоритет найденного оператора больше либо равен сохраненному, проводим вычисления
					{
						process_op(st, op.top());
						op.pop();
					}
					op.push(curop);
				}
				else
				{
					string operand;
					while (i < s.length() && isalnum(s[i]))
					{
						operand += s[i++];
					}
					--i;
					if (isdigit(operand[0]))
					{
						st.push(atoi(operand.c_str()));
					}
				}
			}
		}
		while (!op.empty())
		{
			process_op(st, op.top());
			op.pop();
		}
		return st.top();
	}

};

