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

    vector<vector<int>> graph(n + 1); // �׷��� ���� (1�� ������ ����)
    vector<bool> visited(n + 1, false); // �湮 ���� ���

    // �׷��� �Է�
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // ������ �׷���
    }

    int connected_components = 0;

    // ��� ��忡 ���� Ž��
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited); // ����� ��� ��带 �湮
            connected_components++; // ���ο� ���� ��� �߰�
        }
    }

    cout << connected_components << endl;

    return 0;
}
