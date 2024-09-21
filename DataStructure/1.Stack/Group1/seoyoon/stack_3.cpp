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
		//태그 시작 -> 그대로 출력
		if (ch == '<')
		{
			//스택 안비어 있으면 뒤집어서 출력
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}

			//스택 비어있으면 그냥 출력
			while (ch != '>')
			{
				cout << ch;
				ch = s[++i];
			}
			cout << ch; // '>'도 출력
		}
		
		else if (ch == ' ')
		{
			// 공백 -> 스택 뒤집어 출력
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << ch; //공백도 출력
		}

		else
		{
			// 문자 -> 스택에 넣기
			stk.push(ch);
		}
	}

	//마지막 단어일 경우
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}