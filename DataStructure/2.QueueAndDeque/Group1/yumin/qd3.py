import sys
from collections import deque

n = int(input())
d = deque()

for i in range(n):
    com = sys.stdin.readline().rstrip().split()

    if com[0] == 'push_front': #덱의 앞에 넣음 (왼쪽에서 넣음)
        d.appendleft(com[1])
    elif com[0] == 'push_back': #덱의 뒤에 넣음 (오른쪽에서 넣음)
        d.append(com[1])
    elif com[0] == 'pop_front':
        if len(d) == 0:
            print(-1)
        else:
            print(d[0])
            d.popleft() #앞(왼쪽) pop
    elif com[0] == 'pop_back':
        if len(d) == 0:
            print(-1)
        else:
            print(d[-1])
            d.pop() #뒤(오른쪽) pop
    elif com[0] == 'size':
        print(len(d))
    elif com[0] == 'empty':
        if len(d) == 0:
            print(1)
        else:
            print(0)
    elif com[0] == 'front':
        if len(d) == 0:
            print(-1)
        else:
            print(d[0])
    elif com[0] == 'back':
        if len(d) == 0:
            print(-1)
        else:
            print(d[-1])

    sys.stdout.flush()