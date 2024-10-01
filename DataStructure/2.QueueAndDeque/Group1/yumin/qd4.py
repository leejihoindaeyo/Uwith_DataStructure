from collections import deque
dq = deque()

R = int(input())
doc = deque()

for i in range(R):
    N, M = int(input().split())
    for j in range(N):
        doc.append(input())
    for k in range(M):
        if doc[k] < doc[k+1]:
            doc.append(doc.pop())
