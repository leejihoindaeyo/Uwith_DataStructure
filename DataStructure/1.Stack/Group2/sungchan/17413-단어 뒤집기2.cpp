#include <bits/stdc++.h>
using namespace std;
stack<char> st;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; getline(cin, s);
    auto first_it = s.begin(); auto braket_it = s.begin();
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        if(*it == '<')
        {
            while(!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            braket_it = find(it, s.end(), '>');
            for(auto t = it; t != next(braket_it); ++t)
                cout << *t;
            
            it = (it == s.end() ? s.end() : braket_it);
        }

        else
        {
            if(*it != ' ')
                st.push(*it);

            else
            {
                while(!st.empty())
                {
                    cout << st.top(); 
                    st.pop();
                }
                cout << " ";
            }
        }
    }
    while(!st.empty())
    {
        cout << st.top(); 
        st.pop();
    }

    return 0;
} 