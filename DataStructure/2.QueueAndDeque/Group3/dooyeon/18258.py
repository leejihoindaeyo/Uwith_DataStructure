import sys
from collections import deque

N = int(sys.stdin.readline())
Que = deque()
for _ in range(N):
    sen = sys.stdin.readline().split()
    if sen[0] == 'push': 
        Que.append(int(sen[1]))
    if sen[0] == 'pop':  
        if Que:   
            print(Que.popleft())
        else:
            print(-1)
    if sen[0] == 'size':  
        print(len(Que))
    if sen[0] == 'empty':
        if Que:
            print('0')
        else:
            print('1')
    if sen[0] == 'front':
        if Que:
            print(Que[0])
        else:
            print(-1)
    if sen[0] == 'back':
        if Que:
            print(Que[-1])
        else:
            print(-1)