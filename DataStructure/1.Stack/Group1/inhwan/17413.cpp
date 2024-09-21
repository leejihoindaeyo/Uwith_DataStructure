#include<iostream>
#include<stack>
#include<string>

using namespace std;

int code17413()
{
	string str;
	stack <char> list;
	getline(cin, str);
	//cout << "str : " << str << endl; 
	int i = 0;


	for (i = 0; i < str.size(); i++)
	{
		char st = str[i];

		/*
		if (st == '<')
		{
			while (str[i] != '>')
			{
				cout << str[i];
				i++;
			}
			cout << '>';
		}
		*/
		if (st == ' ' || st == '<')
		{
			while (!list.empty())
			{
				cout << list.top();
				list.pop();
			}
			if (st == '<')
			{
				while (str[i] != '>')
				{
					cout << str[i];
					i++;
				}
				cout << '>';
			}
			if (st == ' ')
			{
				cout << ' ';
			}
		}

		else
		{
			//cout << "push : " << st << endl;
			list.push(st);
		}
	}

	while (!list.empty())
	{

		cout << list.top();
		list.pop();

	}

	return 0;
}