# bfs 이용
from collections import deque

N = int(input())

graph = [[] for i in range(N+1)]
for i in range(N-1):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [0] * (N+1)

def bfs(start):
    deq = deque([start])

    while deq:
        node = deq.popleft()
        for ad in graph[node]:
            if visited[ad] == 0:
                visited[ad] == node
                deq.append(ad)

bfs(1)
answer = visited[2:]
for x in answer:
    print(x)


