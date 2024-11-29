#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // 그래프 저장 (1번 노드부터 시작)
    vector<bool> visited(n + 1, false); // 방문 여부 기록

    // 그래프 입력
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프
    }

    int connected_components = 0;

    // 모든 노드에 대해 탐색
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited); // 연결된 모든 노드를 방문
            connected_components++; // 새로운 연결 요소 발견
        }
    }

    cout << connected_components << endl;

    return 0;
}
