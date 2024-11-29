N,M,V = map(int,input().split())

nodes = [[0]*(N+1) for _ in range(N+1)]
for i in range (M):
    a,b = map(int,input().split())
    nodes[a][b] = 1 
    nodes[b][a] = 1

visited1 = [0]*(N+1)
visited2 = visited1.copy()

def DFS(V):
    visited1[V] = 1 
    print(V, end=' ')
    
    for i in range(1, N+1):
        if nodes[V][i] == 1 and visited1[i] == 0:
            DFS(i)


def BFS(V):
    li = [V]
    visited2[V] = 1
    
    while li:
        V = li.pop(0) 
        print(V, end = ' ')
        
        for i in range(1, N+1):
            if(visited2[i] == 0 and nodes[V][i] == 1):
                li.append(i)
                visited2[i] = 1

DFS(V)
print()
BFS(V)