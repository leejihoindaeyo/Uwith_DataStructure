#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	else
		return 0;
}

int main()
{
	string s;
	cin >> s;

	stack<char> stk;
	string result = "";

	for (char ch : s)
	{
		//���ڸ� �����
		if (isalpha(ch))
			result += ch;

		//���� ��ȣ������ ����
		else if (ch == '(')
			stk.push(ch);

		//�ݴ� ��ȣ������
		else if (ch == ')')

		{	//���� �� ������ ������ ���
			while (!stk.empty() && stk.top() != '(')
			{
				result += stk.top();
				stk.pop();
			}

			//���ÿ� �ִ� ���� ��ȣ ����
			stk.pop();
		}

		//������ ������
		else
		{
			//������ ������ �켱������ ������ ���� ���
			while (!stk.empty() && priority(stk.top()) >= priority(ch))
			{
				result += stk.top();
				stk.pop();
			}
			stk.push(ch);
		}

	}

	//���ÿ� ���� �ִ� ������ ���
	while (!stk.empty())
	{
		result += stk.top();
		stk.pop();
	}

	cout << result << endl;
	return 0;
}