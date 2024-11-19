import sys
from collections import deque
input = sys.stdin.readline


n, m = map(int, input().split())
tree = [[] for _ in range(n+1)]


def bfs(a, b):
    q = deque()
    q.append((a, 0))
    visited = [False] * (n+1)
    visited[a] = True
    while q:
        start, distance = q.popleft()

        if start == b:
            return distance

        for i, j in tree[start]:
            if not visited[i]:
                q.append((i, distance+j))
                visited[i] = True


for _ in range(n-1):
    a, b, distance = map(int ,input().split())
    tree[a].append((b, distance))
    tree[b].append((a, distance))

for _ in range(m):
    a, b = map(int, input().split())
    print(bfs(a, b))