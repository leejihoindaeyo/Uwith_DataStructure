#include<iostream>
#include<stack>

using namespace std;


int code9012()
{
	int num;
	cin >> num;
	string str;


	for (int i = 0; i < num; i++)
	{
		stack <char> list;
		int check_vps = 0; //0: vps성립o, 1:vps성립x

		cin >> str;
		for (char st : str)
		{
			if (st == '(')
			{
				list.push(st); // '('만 stack에 추가
			}
			else if (st == ')')
			{
				if (list.empty()) //비어있다면 vps x
				{ 
					check_vps = 1;
					break;
				}
				list.pop(); //비어 있지 않다면 빼기
			}
		}
		if (!list.empty()) // 비어있지 않다면 vps x, '!'로 반대로 만듬
		{
			check_vps = 1;
		}
		if (check_vps) // check)vps = 1 이라면 vps 성립x
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}

	return 0;
}