
n, M, v = map(int,input().split())

m = [[0]*(n+1) for i in range(n+1)]

visited = [0] *(n+1)

for i in range(M):
    a,b = map(int,input().split())
    m[a][b] = m[b][a] = 1


# dfs
def dfs(v):
    visited[v] = 1
    print(v, end = " ")
    for i in range(1, n+1):
        if visited[i] == 0 and m[v][i] == 1:
            dfs(i)

# bfs
def bfs(v):
    queue = [v] 
    visited[v] = 0
    while queue:
        v = queue.pop(0)
        print(v, end = ' ')
        for i in range(1, n+1):
            if visited[i] == 1 and m[v][i] == 1:
                queue.append(i)
                visited[i] = 0

dfs(v)
print()
bfs(v)