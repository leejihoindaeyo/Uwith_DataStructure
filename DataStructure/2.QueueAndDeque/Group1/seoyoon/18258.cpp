#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	//iostream과 stdio동기화 비활성화 -> 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, ch;
	string s;

	cin >> num;

	queue<int> que;

	for (int i = 0; i < num; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> ch;
			que.push(ch);
		}
		else if (s == "pop")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
			{
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (s == "front")
		{
			cout << (que.empty() ? -1 : que.front()) << '\n';
		}
		else if (s == "back")
		{
			cout << (que.empty() ? -1 : que.back()) << '\n';
		}
		else if (s == "size")
		{
			cout << que.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << que.empty() << '\n';
		}
	}
	return 0;
}