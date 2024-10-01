#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

int code10828()
{
	int num;
	stack<int> list;
	cin >> num;
	string str;
	int a;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		cin.ignore();
		//cout << str << endl;
		if (str == "push")
		{
			cin >> a;
			list.push(a);
		}
		else if (str == "pop")
		{
			if (list.empty() == 1)
			{
				printf("-1\n");
			}
			else
			{
				//cout << "pop ����" << endl;
				cout << list.top() << endl;
				list.pop();
			}
		}
		else if (str == "size")
		{
			//cout << "size ����" << endl;
			cout << list.size();
			printf("\n");
		}
		else if (str == "empty")
		{
			//cout << "empty ����" << endl;
			cout << list.empty();
			printf("\n");
		}
		else if (str == "top")
		{
			//cout << "top ����" << endl;
			if (list.empty() == 1)
			{
				printf("-1\n");
			}
			else
			{
				cout << list.top();
				printf("\n");
			}
		}
	}
	return 0;
}