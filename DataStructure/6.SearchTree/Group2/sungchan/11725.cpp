#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int ans[100001];
bool vis[100001];
int n;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1); vis[1] = 1;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto c : adj[cur])
        {
            if(vis[c]) continue;
            ans[c] = cur;
            vis[c] = 1; q.push(c);
        }
    }
    
    for(int i = 2; i <= n ;i++)
        cout << ans[i] << '\n';
    return 0;
}