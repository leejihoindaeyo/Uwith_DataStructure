#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_vps(const string s)
{
	stack<char> vps;

	for (char ch : s)
	{
		if (ch == '(')
			vps.push('(');
		else if (ch == ')')
		{
			if (vps.empty())
				return false;
			else
				vps.pop();
		}
	}

	if (vps.empty())
		return true;
	else
		return false;

}

int main()
{
	int num;
	string s;

	cin >> num;
	for (int i=0; i < num; i++)
	{
		cin >> s;
		if (is_vps(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}