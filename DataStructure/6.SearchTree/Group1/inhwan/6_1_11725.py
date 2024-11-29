from collections import deque
n=int(input())
q=deque([1])
tree=dict()   #딕셔너리
for i in range(1,n+1):
    tree[i]=[]
for j in range(n-1):
    a,b = map(int, input().split())
    tree[a].append(b)   #key=a, value = b
    tree[b].append(a)   #key=b, value = a

parent = [0]*(n+1)
while q:
    now = q.popleft() #queue pop
    for i in tree[now]:
        if parent[i]==0 and i!=1:
            parent[i]=now
            q.append(i)
for i in range(2,n+1):
    print(parent[i])