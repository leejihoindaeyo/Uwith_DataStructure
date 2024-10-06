#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	string s = "";
	cin >> s;
	// 문자열의 시작부터 끝까지 리스트로 저장
	list<char> l(s.begin(), s.end());

	auto pos = l.end();

	int num;
	cin >> num;

	while (num--)
	{
		char command, letter;
		cin >> command;

		if (command == 'L')
		{
			if (pos != l.begin())
				pos--;
		}
		else if (command == 'D')
		{
			if (pos != l.end())
				pos++;
		}
		else if (command == 'B')
		{
			if (pos != l.begin())
			{
				pos--;
				pos = l.erase(pos);
			}
		}
		else if (command == 'P')
		{
			cin >> letter;
			l.insert(pos, letter);
		}
	}

	for (pos = l.begin(); pos != l.end(); pos++)
	{
		cout << *pos;
	}

	return 0;
}