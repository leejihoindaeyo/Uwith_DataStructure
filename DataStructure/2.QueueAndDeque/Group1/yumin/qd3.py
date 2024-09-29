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

#문자열 크기 비교 할 때 if len(d) == '0'으로 작성하는 바보같은 실수를 함...
#명령 입력을 com = sys.stdin.readline().split()으로 받았더니 마지막 명령의 결과가 바로 출력되지 않음.
#com = sys.stdin.readline().split()으로 명령을 받았던 걸 strip()을 추가해 명령 줄바꿈 문자를 제거하고
# sys.stdout.flush()를 추가해 출력을 즉시 플러시하도록 함
#여전히 해결 안 됨. 입력을 한 번 더 받고 나서야 마지막 결과값이 출력됨...