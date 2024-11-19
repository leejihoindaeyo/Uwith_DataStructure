import sys
N=int(sys.stdin.readline().rstrip())

arr=list(map(int, sys.stdin.readline().rstrip().split()))

erase=int(input())

def dfs(index):
    arr[index]=-2
    for i in range(N):
        if arr[i]==index:
            dfs(i)

dfs(erase)
answer=0

for i in range(N):
    if not arr[i]==-2 and i not in arr:
        answer+=1

print(answer)