#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

long long cal(long long num1, long long num2, char op) {
    if (op == '+') {
        return num1 + num2;
    }
    else if (op == '-') {
        return num1 - num2;
    }
    else if (op == '*') {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

int main(void) {   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    deque<long long> number;
    deque<char> op;
    bool first = false;
    long long num = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0 && s[i] == '-') {
            first = true;
        }
        else if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else {
            if (first) {
                first = false;
                num *= -1;
            }
            number.push_back(num);
            op.push_back(s[i]);
            num = 0;
        }
    }

    if (first) {
        first = false;
        num *= -1;
    }
    number.push_back(num);
    
    if (number.size() == 1) {
        cout << number.front();
        return 0;
    }

    while (true) {
        long long tmp[4] = {0};
        if (number.size() == 3) {
            tmp[0] = number.front();
            tmp[3] = number.back();
            number.pop_back();
            number.pop_front();
            tmp[1] = tmp[2] = number.front();
        }
        else if (number.size() == 2) {
            tmp[0] = number.front();
            tmp[1] = number.back();
        }
        else {
            tmp[0] = number.front();
            tmp[3] = number.back();
            number.pop_back();
            number.pop_front();
            tmp[1] = number.front();
            tmp[2] = number.back();
        }

        if (op.size() == 1) {
            char oper = op.front();
            cout << cal(tmp[0], tmp[1], oper);
            return 0;
        }
        else {
            char oper1 = op.front();
            char oper2 = op.back();

            if (oper1 == '+' || oper1 == '-') {
                if (oper2 == '*' || oper2 == '/') {
                    op.pop_back();
                    number.pop_back();
                    number.push_back(cal(tmp[2], tmp[3], oper2));
                    number.push_front(tmp[0]);
                }
                else {
                    long long num1 = cal(tmp[0], tmp[1], oper1);
                    long long num2 = cal(tmp[2], tmp[3], oper2);

                    if (num1 >= num2) {
                        op.pop_front();
                        number.pop_front();
                        number.push_front(num1);
                        number.push_back(tmp[3]);
                    }
                    else {
                        op.pop_back();
                        number.pop_back();
                        number.push_back(num2);
                        number.push_front(tmp[0]);
                    }
                }
            }
            else if (oper1 == '*' || oper1 == '/') {
                if (oper2 == '+' || oper2 == '-') {
                    op.pop_front();
                    number.pop_front();
                    number.push_front(cal(tmp[0], tmp[1], oper1));
                    number.push_back(tmp[3]);
                }
                else {
                    long long num1 = cal(tmp[0], tmp[1], oper1);
                    long long num2 = cal(tmp[2], tmp[3], oper2);

                    if (num1 >= num2) {
                        op.pop_front();
                        number.pop_front();
                        number.push_front(num1);
                        number.push_back(tmp[3]);
                    }
                    else {
                        op.pop_back();
                        number.pop_back();
                        number.push_back(num2);
                        number.push_front(tmp[0]);
                    }
                }
            }
        }
    }

    return 0;
}
