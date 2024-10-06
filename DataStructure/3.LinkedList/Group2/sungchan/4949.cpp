#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string str;
        getline(cin, str);
        bool isVaild = true;
        if (str == ".") break;
        stack<char> st;
        for (auto c : str) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    isVaild = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    isVaild = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            isVaild = false;
        if (isVaild)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}