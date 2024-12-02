#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    // 우선순위 큐 <노드,노드>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0; // 시작 노드의 거리 0
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 이미 처리된 노드면 스킵
        if (current_dist > dist[current_node]) continue;

        // 인접 노드 탐색
        for (const auto& edge : graph[current_node]) {
            int next_node = edge.first;
            int weight = edge.second;

            // 더 짧은 경로 발견 시 업데이트
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

    // 그래프 입력: 인접 리스트
    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    // 최단 거리 초기화
    vector<int> dist(V + 1, INF);

    // 다익스트라 실행
    dijkstra(start, graph, dist);

    // 결과 출력
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}