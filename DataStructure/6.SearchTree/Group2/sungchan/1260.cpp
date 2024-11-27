#include <bits/stdc++.h>
using namespace std;
bool vis[1001];
vector<int> adj[1001];
queue<int> q;
void dfs(int x)
{
	vis[x] = 1;
	cout << x << " ";
	for (int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if (!vis[y]) 
            dfs(y);
	}
}
int n, m, v;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i < n+1; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(v); cout << '\n';

    fill(vis, vis+1001, 0);

    vis[v] = 1; q.push(v);
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        cout << cur << " ";
        for(auto it : adj[cur])
        {
            if(vis[it]) continue;
            vis[it] = 1;
            q.push(it);
        }
    }
    return 0;
}