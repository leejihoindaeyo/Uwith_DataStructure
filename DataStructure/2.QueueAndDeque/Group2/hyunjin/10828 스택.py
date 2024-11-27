import sys

stack = []
n = int(input())  # 명령의 수를 입력받음

for i in range(n):
    s = sys.stdin.readline().split()

    if s[0] == 'push':
        stack.append(s[1])  # 'append'를 올바르게 사용

    elif s[0] == 'pop':
        if len(stack) > 0:
            print(stack.pop())
        else:
            print(-1)

    elif s[0] == 'size':
        print(len(stack))

    elif s[0] == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    elif s[0] == 'top':  # 'top' 명령이 누락된 부분 추가
        if len(stack) > 0:
            print(stack[-1])
        else:
            print(-1)
