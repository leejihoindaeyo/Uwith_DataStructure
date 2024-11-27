#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int len = s.length(); int count = 0;
    for(int i = 1; i <= len; i++)
    {
        int aim_count = 0; set<string> st;
        for(int j = 0; j <= len-i; j++)
        {
            string ex = s.substr(j, i);
            if(st.insert(ex).second){
                aim_count++;
            }
        }
        count += aim_count;
    }
    cout << count << '\n';
    return 0;
}