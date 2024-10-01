#include <bits/stdc++.h>
using namespace std;
vector<int> vc;
deque<int> dq;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        vc.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(vc[i] == 0) dq.push_back(a);
        else continue;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        dq.push_front(a);
        cout << dq.back() << " "; dq.pop_back();
    }
    return 0;
}