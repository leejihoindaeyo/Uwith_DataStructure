#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> stk;
	string s;

	getline(cin, s);

	for (int i = 0; i < s.size(); i++)

	{
		char ch = s[i];
		//�±� ���� -> �״�� ���
		if (ch == '<')
		{
			//���� �Ⱥ�� ������ ����� ���
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}

			//���� ��������� �׳� ���
			while (ch != '>')
			{
				cout << ch;
				ch = s[++i];
			}
			cout << ch; // '>'�� ���
		}
		
		else if (ch == ' ')
		{
			// ���� -> ���� ������ ���
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << ch; //���鵵 ���
		}

		else
		{
			// ���� -> ���ÿ� �ֱ�
			stk.push(ch);
		}
	}

	//������ �ܾ��� ���
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}