#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;getline(cin, str);
        stack<char> st;
        bool isVaild = true;
        for (auto c : str)
        {
            if (c == '(')
                st.push(c);

            else if (c == ')')
            {
                if (st.empty() || st.top() != '(') {
                    isVaild = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            isVaild = false;
        if (isVaild)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}