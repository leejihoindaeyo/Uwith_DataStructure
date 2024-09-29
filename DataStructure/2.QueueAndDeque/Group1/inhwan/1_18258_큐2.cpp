#include<iostream>
#include<queue>

using namespace std;

int code18258()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;
	queue<int> list;


	for (int i = 0; i < num; i++)
	{
		string str;
		int a;
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			list.push(a);
		}
		else if (str == "pop")
		{
			if (list.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << list.front() << endl;
				list.pop();
			}
		}
		else if (str == "size")
		{
			cout << list.size() << endl;
		}
		else if (str == "empty")
		{
			cout << list.empty() << endl;
		}
		else if (str == "front")
		{
			if (list.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << list.front() << endl;
			}
		}
		else if (str == "back")
		{
			if (list.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << list.back() << endl;
			}
		}
	}

	return 0;
}