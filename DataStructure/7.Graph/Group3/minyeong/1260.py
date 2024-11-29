import sys
from collections import deque
input = sys.stdin.readline

# dfs 함수 정의(재귀)
def dfs(graph, v, visited):
    visited[v] = True # 방문 처리
    print(v, end=' ') # 현재 노드 출력
    for i in sorted(graph[v]): # 오름차순으로 이웃한 노드
        if not visited[i]: # 아직 방문하지 않은 노드가 있다면 방문
            dfs(graph, i, visited)

# bfs 함수 정의
def bfs(graph, start, visited):
    queue = deque([start]) # 큐에 현재 노드 삽입
    visited[start] = True # 방문 처리
    while queue: # 큐가 빌때 동안
        v = queue.popleft()
        print(v, end=' ') # 현재 노드 출력
        for i in sorted(graph[v]): # 오름차순으로 이웃한 노드
            if not visited[i]: # 아직 방문하지 않았다면
                queue.append(i) # 큐에 삽입
                visited[i] = True # 방문처리

n, m, start = map(int, input().rstrip().split()) # 정점, 간선, 시작정점

graph = [[] for j in range(n+1)] # 그려질 그래프 초기화
for k in range(m):
    a, b = map(int, input().rstrip().split()) # 이웃한 정점 연결시킴
    graph[a].append(b)
    graph[b].append(a)


visited = [False] * (n+1)
# dfs 함수 실행
dfs(graph, start, visited)

print()

visited = [False] * (n+1)
# bfs 함수 실행
bfs(graph, start, visited)
