from collections import deque

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
m = int(input())
C = list(map(int, input().split()))

q = deque()
for i in range(n):
    if A[i] == 0:  # 큐일 때
        q.appendleft(B[i])  # B의 원소

for j in range(m):
    q.append(C[j])
    print(q.popleft(), end = ' ')