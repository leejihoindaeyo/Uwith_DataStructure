#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    // �켱���� ť <���,���>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0; // ���� ����� �Ÿ� 0
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // �̹� ó���� ���� ��ŵ
        if (current_dist > dist[current_node]) continue;

        // ���� ��� Ž��
        for (const auto& edge : graph[current_node]) {
            int next_node = edge.first;
            int weight = edge.second;

            // �� ª�� ��� �߰� �� ������Ʈ
            if (dist[current_node] + weight < dist[next_node]) {
                dist[next_node] = dist[current_node] + weight;
                pq.push({ dist[next_node], next_node });
            }
        }
    }
}

int main() {
    int V, E, start;
    cin >> V >> E >> start;

    // �׷��� �Է�: ���� ����Ʈ
    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    // �ִ� �Ÿ� �ʱ�ȭ
    vector<int> dist(V + 1, INF);

    // ���ͽ�Ʈ�� ����
    dijkstra(start, graph, dist);

    // ��� ���
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}