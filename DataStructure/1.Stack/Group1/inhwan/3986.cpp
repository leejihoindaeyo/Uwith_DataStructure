#include<iostream>
#include<stack>

using namespace std;

int code3986()
{
	int num;
	cin >> num;
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		string str;
		stack<char>list;
		cin >> str;
		int n = str.size();
		list.push(str[0]);

		for(int k=1; k<n; k++)
		{	
			if (!list.empty() && list.top() == str[k])
			{
				list.pop(); //같으면 뽑기
			}
			else {
				list.push(str[k]);
			}
		}
		if (list.empty())
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}