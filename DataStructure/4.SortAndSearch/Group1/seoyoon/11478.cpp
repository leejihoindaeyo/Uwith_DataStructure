#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	unordered_set<string> subStrings;

	//������ ��� �κ� ���ڿ�
	for (int i = 0; i < s.size(); i++)
	{
		string substring = "";
		for (int j = i; j < s.size(); j++)
		{
			substring += s[j];
			subStrings.insert(substring);
		}
	}

	cout << subStrings.size() << endl;

	return 0;
}