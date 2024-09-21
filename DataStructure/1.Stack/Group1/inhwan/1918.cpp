#include<iostream>
#include<stack>

using namespace std;

int count(char ch)
{
	if (ch == '(') return 0;//리스트에 여는괄호도 들어가는 있으니 안나오독 만들기 위함
	else if (ch == '+' || ch == '-') return 1;
	else if (ch == '*' || ch == '/') return 2;
	return -1;
}

int main()
{
	string str;
	stack <char> list;
	//중위 표기법 a*b
	//전위 표기법 *ab
	//후위 표기법 ab*

	cin >> str;
	
	for (int i = 0; i <str.size(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90) //알파벳일때
		{
			cout << str[i];
		}
		else if (!(str[i] >= 65 && str[i] <= 90)) //알파벳이 아닐때
		{
			if (str[i] == '(')
			{
				//cout << i <<1;
				list.push(str[i]); // 여는 괄호를 포함하여 특수문자 push

			}
			else if (str[i] == ')')
			{
				while (!list.empty() && list.top() != '(') //여는 괄호가 가장 위로 올라오면 종료
				{
					cout << list.top();
					list.pop();
				}
				list.pop(); //마지막 남은 여는 괄호 삭제
			}
			else //다른 특수문자들
			{
				while (!list.empty() && count(list.top()) >= count(str[i]))
				{
					cout << list.top();
					list.pop();
				}
				list.push(str[i]);
			}
			
		}

	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!list.empty())
		{
			cout << list.top();
			list.pop();
		}
	}
	return 0;
}