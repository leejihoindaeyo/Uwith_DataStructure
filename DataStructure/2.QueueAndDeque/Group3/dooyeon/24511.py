import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split())) 
B = list(map(int, input().split())) 
M = int(input())                             
C = list(map(int, input().split())) 
que = deque([])

for i in range(N):
    if A[i] == 0:
        que.appendleft(B[i])
else:
    if que == []:
        print(*C)
        sys.exit()
for i in range(M):
    que.append(C[i])
    print(que.popleft(), end = " ")