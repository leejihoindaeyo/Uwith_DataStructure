#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node); // 방문한 노드 저장

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
}

void bfs(int start, const vector<vector<int>>& graph, vector<int>& result) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node); // 방문한 노드 저장

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1); // 그래프 저장 (1번 노드부터 시작)

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 정점 번호가 작은 순서대로 방문하기 위해 정렬
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(n + 1, false);
    vector<int> dfs_result, bfs_result;

    dfs(v, graph, visited, dfs_result);
    bfs(v, graph, bfs_result);

    // DFS 결과 출력
    for (size_t i = 0; i < dfs_result.size(); ++i) {
        cout << dfs_result[i] << (i == dfs_result.size() - 1 ? "\n" : " ");
    }

    // BFS 결과 출력
    for (size_t i = 0; i < bfs_result.size(); ++i) {
        cout << bfs_result[i] << (i == bfs_result.size() - 1 ? "\n" : " ");
    }

    return 0;
}
