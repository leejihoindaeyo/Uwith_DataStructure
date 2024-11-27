import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**6)

N, M = map(int, input().split())

nodes = [[] for _ in range(N+1)]
ans = 0

for _ in range(M):
    a, b = map(int, input().split())
    nodes[a].append(b)
    nodes[b].append(a)

visited = [False] * (N+1)

def DFS(x):
    visited[x] = True
    for node in nodes[x]:
        if not visited[node]:
            DFS(node)

for i in range(1, N+1):
    if not visited[i]:
        DFS(i)
        ans += 1

print(ans)
