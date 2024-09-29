#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <deque>
using namespace std;

string input;
deque<string> calc_data;

long long Calc(long long num1, string oper, long long num2)
{
	long long ret;
	if (oper == "+")
	{
		ret = num1 + num2;
	}

	else if (oper == "-")
	{
		ret = num1 - num2;
	}

	else if (oper == "*")
	{
		ret = num1 * num2;
	}

	else if (oper == "/")
	{
		ret = num1 / num2;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> input;

	string temp = "";
	for (long long i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '*' || input[i] == '-' || input[i] == '/')
		{
			if (i != 0)
			{
				calc_data.push_back(temp); //연산자 앞의 수 저장
				temp = "";

				temp += input[i];
				calc_data.push_back(temp); //연산자 저장
				temp = "";

			}

			else //맨 앞에는 음수가 들어올 수 있다
			{
				temp += input[i];
			}
		}

		else
		{
			temp += input[i];

			if (i == input.size() - 1) //마지막 숫자일때
				calc_data.push_back(temp);
		}
	}

	while (calc_data.size() != 1)
	{
		string oper1;
		string oper2;
		long long temp_result1;
		long long temp_result2;

		oper1 = calc_data[1]; //앞의 연산자
		oper2 = calc_data[calc_data.size() - 2]; //뒤의 연산자

		if ((oper1 == "*" || oper1 == "/") && (oper2 == "+" || oper2 == "-"))
		{
			temp_result1 = Calc(stoll(calc_data[0]), oper1, stoll(calc_data[2]));

			calc_data.pop_front();
			calc_data.pop_front();
			calc_data.pop_front();
			calc_data.push_front(to_string(temp_result1));
		}

		else if ((oper1 == "+" || oper1 == "-") && (oper2 == "*" || oper2 == "/"))
		{
			temp_result2 = Calc(stoll(calc_data[calc_data.size() - 3]), oper2, stoll(calc_data[calc_data.size() - 1]));

			calc_data.pop_back();
			calc_data.pop_back();
			calc_data.pop_back();
			calc_data.push_back(to_string(temp_result2));
		}

		else //연산자 우선순위가 같을때
		{
			temp_result1 = Calc(stoll(calc_data[0]), oper1, stoll(calc_data[2]));
			temp_result2 = Calc(stoll(calc_data[calc_data.size() - 3]), oper2, stoll(calc_data[calc_data.size() - 1]));

			if (temp_result1 >= temp_result2)
			{
				calc_data.pop_front();
				calc_data.pop_front();
				calc_data.pop_front();
				calc_data.push_front(to_string(temp_result1));
			}

			else
			{
				calc_data.pop_back();
				calc_data.pop_back();
				calc_data.pop_back();
				calc_data.push_back(to_string(temp_result2));
			}
		}
	}

	cout << stoll(calc_data[0]);

	return 0;
}