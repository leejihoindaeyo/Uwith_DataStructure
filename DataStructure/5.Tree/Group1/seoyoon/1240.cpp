#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[1001];
bool visited[1001];
int result;

void dfs(int current, int target, int distance) {
    if (current == target) {
        result = distance;
        return;
    }
    visited[current] = true;
    for (auto& neighbor : tree[current]) {
        if (!visited[neighbor.first]) {
            dfs(neighbor.first, target, distance + neighbor.second);
        }
    }
}

int main() {
    int n, u, v, w, start, end;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        tree[u].push_back({ v, w });
        tree[v].push_back({ u, w });
    }
    cin >> start >> end;
    memset(visited, false, sizeof(visited));
    dfs(start, end, 0);
    cout << result << endl;
    return 0;
}
