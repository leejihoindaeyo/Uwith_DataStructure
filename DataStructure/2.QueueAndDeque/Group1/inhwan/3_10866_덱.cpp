#include<iostream>
#include<deque>

using namespace std;

int code10866()
{
	deque<int>list;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string str;
		cin >> str;
		if (str == "push_back")
		{
			int x;
			cin >> x;
			list.push_back(x);
		}
		else if (str == "push_front")
		{
			int x;
			cin >> x;
			list.push_front(x);
		}
		else if (str == "pop_front")
		{
			if (!list.empty()) {
				cout << list.front() << '\n';
				list.pop_front();
			}
			else cout << "-1" << '\n';
		}
		else if (str == "pop_back")
		{
			if (!list.empty()) {
				cout << list.back() << "\n";
				list.pop_back();
			}
			else cout << "-1" << '\n';
		}
		else if (str == "front")
		{
			if (!list.empty()) {
				cout << list.front() << '\n';
			}
			else cout << "-1" << '\n';
		}
		else if (str == "back")
		{
			if (!list.empty()) {
				cout << list.back() << '\n';
			}
			else cout << "-1" << '\n';
		}
		else if (str == "size")
		{
			cout << list.size() << '\n';
		}
		else if (str == "empty")
		{
			cout << list.empty() << '\n';
		}
	}
	return 0;
}