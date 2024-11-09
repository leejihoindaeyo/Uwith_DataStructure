#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	string str;
	cin >> str;
	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		vector<std::string> v;

		for (int j = 0; j < str.size() - i; j++)
		{
			string tmp = str.substr(j, 1 + i);
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());
        // 중복된 요소를 끝으로 이동시켜 끝부분 지워주기
		v.erase(unique(v.begin(), v.end()), v.end());
		count += v.size();
	}

	cout << count << endl;
    return 0;
}