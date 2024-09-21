#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack<int> s;
	int num, idx;
	string com;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> com;

		if (com == "push")
		{
			cin >> idx;
			s.push(idx);
		}

		else if (com == "pop")
		{
			if (s.empty())
				cout << -1 << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
				
		}

		else if (com == "size")
		{
			cout << s.size() << endl;
		}

		else if (com == "empty")
		{
			cout << (s.empty() ? 1 : 0) << endl;
		}

		else if (com == "top")
		{
			cout << (s.empty() ? -1 : s.top()) << endl;
		}
	}

	return 0;
}