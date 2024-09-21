#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isGoodWord(const string s);

int main()
{
	int num;
	int count = 0;
	string s;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> s;
		if (isGoodWord(s))
			count++;
	}
	cout << count;

	return 0;
}

bool isGoodWord(const string s)
{
	stack<char> stk;

	for (char ch : s)
	{
		if (!stk.empty() && ch == stk.top())
			stk.pop();
		else
			stk.push(ch);
	}

	return stk.empty();
}