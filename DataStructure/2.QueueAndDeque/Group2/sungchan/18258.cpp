#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n; cin >> n;
    while(n--)
    {
        string a; cin >> a;
        if(a == "push"){
            int k; cin >> k;
            q.push(k);
        }
        else if(a == "front"){
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }

        else if(a == "back"){
            if(q.empty()) cout << "-1\n";
            else cout << q.back()<< '\n';
        }

        else if(a == "size")
            cout << q.size() << '\n';

        else if(a == "pop")
        {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.front() << '\n'; q.pop();
            }
        }
        else if(a == "empty"){
            if(q.empty()) cout << q.empty() << '\n';
            else cout << q.empty() << '\n';
        }
    }
    return 0;
}