#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool vis[1001];
int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        count++;
        q.push(i); vis[i] = 1;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for(auto c : adj[cur])
            {
                if(vis[c]) continue;
                q.push(c);
                vis[c] = 1;
            }
        }
    }
    cout << count << '\n';
    return 0;
}