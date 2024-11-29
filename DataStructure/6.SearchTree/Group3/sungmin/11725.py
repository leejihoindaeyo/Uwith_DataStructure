# 11725번 트리의 부모 찾기

import sys
input = sys.stdin.readline

N = int(input())
nodes = [[0] for _ in range(N+1)]
parent = [0]*(N+1)

for _ in range(N-1):
    a, b = map(int, input().split())
    nodes[a].append(b)
    nodes[b].append(a)
    
parent[1] = 0
q = [1] 

while q:
    current = q.pop(0) 
    for v in nodes[current]:
        if parent[v] == 0:
            parent[v] = current
            q.append(v)

print('\n'.join(map(str, parent[2:])))
