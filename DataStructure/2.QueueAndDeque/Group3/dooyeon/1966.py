import sys
from collections import deque
input = sys.stdin.readline

test = int(input())
for _ in range(test):
    N, M = map(int, input().split())
    Que = deque(list(map(int, input().split())))
    if N == 1:
        print(1)
    else:
        cnt = 0
        while Que:
            temp = Que.popleft()
            if Que and max(Que) > temp:
                Que.append(temp)
            else:
                cnt += 1
                if M == 0:
                    break
            M = (M-1) % len(Que)          
        print(cnt)