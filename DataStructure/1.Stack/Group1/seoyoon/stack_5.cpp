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
		//문자면 결과에
		if (isalpha(ch))
			result += ch;

		//여는 괄호만나면 스택
		else if (ch == '(')
			stk.push(ch);

		//닫는 괄호나오면
		else if (ch == ')')

		{	//스택 빌 때까지 연산자 출력
			while (!stk.empty() && stk.top() != '(')
			{
				result += stk.top();
				stk.pop();
			}

			//스택에 있던 여는 괄호 제거
			stk.pop();
		}

		//연산자 만나면
		else
		{
			//스택의 연산자 우선순위가 높으면 먼저 출력
			while (!stk.empty() && priority(stk.top()) >= priority(ch))
			{
				result += stk.top();
				stk.pop();
			}
			stk.push(ch);
		}

	}

	//스택에 남아 있는 연산자 출력
	while (!stk.empty())
	{
		result += stk.top();
		stk.pop();
	}

	cout << result << endl;
	return 0;
}