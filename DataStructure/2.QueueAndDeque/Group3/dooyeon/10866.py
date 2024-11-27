from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
deq = deque([])

for _ in range(N):
    st = input().split()
    if "push_front" == st[0]:
        deq.appendleft(st[1])
    elif "push_back" == st[0]:
        deq.append(st[1])
    elif "pop_front" == st[0]:
        if deq:
            print(deq.popleft())
        else:
            print(-1)
    elif "pop_back" == st[0]:
        if deq:
            print(deq.pop())
        else:
            print(-1)
    elif "size" == st[0]:
        print(len(deq))
    elif "empty" == st[0]:
        if deq:
            print(0)
        else:
            print(1)
    elif "front" == st[0]:
        if deq:
            print(deq[0])
        else:
            print(-1)
    else:
        if deq:
            print(deq[-1])
        else:
            print(-1)