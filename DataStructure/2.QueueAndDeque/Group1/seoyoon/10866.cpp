#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	//iostream과 stdio동기화 비활성화 -> 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	deque<int> deq;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> s;

		if (s == "push_front")
		{
			int push_num;
			cin >> push_num;
			deq.push_front(push_num);
		}

		else if (s == "push_back")
		{
			int push_num;
			cin >> push_num;
			deq.push_back(push_num);
		}

		else if (s == "pop_front")
		{
			if (!deq.empty())
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else
				cout << -1 << '\n';
		}

		else if (s == "pop_back")
		{
			if (!deq.empty())
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else
				cout << -1 << '\n';
		}

		else if (s == "size")
			cout << deq.size() << '\n';

		else if (s == "empty")
			cout << (deq.empty() ? 1 : 0) << '\n';
		else if (s == "front")
			cout << (deq.empty() ? -1 : deq.front()) << '\n';
		else if (s == "back")
			cout << (deq.empty() ? -1 : deq.back()) << '\n';
	}

	return 0;
}