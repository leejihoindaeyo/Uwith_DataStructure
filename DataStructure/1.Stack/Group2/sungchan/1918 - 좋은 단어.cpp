#include <bits/stdc++.h>
using namespace std;
vector<string> vc;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, count = 0; 
    cin >> n; vc.resize(n);
    for(int i = 0; i < n; i++)
        cin >> vc[i];

    for(int i = 0; i < n; i++)
    {
        stack<char> st;
        for(size_t c = 0; c < vc[i].size(); ++c)
        {
            if(!st.empty() && st.top() == vc[i][c])
                st.pop();
            
            else
                st.push(vc[i][c]);
        }
        if(st.empty())
            count++;
    }
    cout << count << '\n';
    return 0;
}   