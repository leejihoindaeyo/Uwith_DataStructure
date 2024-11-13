#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::string str;
	std::cin >> str;
	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		std::vector<std::string> v;

		for (int j = 0; j < str.size() - i; j++)
		{
			std::string tmp = str.substr(j, 1 + i);
			v.push_back(tmp);
		}

		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
		count += v.size();
	}

	std::cout << count;
}