import sys
from collections import deque

input = sys.stdin.readline

n,m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    i,j,k = map(int,input().split())
    graph[i].append((j,k))
    graph[j].append((i,k))

for _ in range(m):
    s,e = map(int,input().split())
    q = deque()
    q.append((s,0))

    visited = [False] * (n+1)
    visited[s] = True

    while q:
        x,dist = q.popleft()

        if x == e:
            print(dist)
            break
        for num,val in graph[x]:
            if not visited[num]:
                visited[num] = True
                q.append((num, dist+val))eturn 0;
}