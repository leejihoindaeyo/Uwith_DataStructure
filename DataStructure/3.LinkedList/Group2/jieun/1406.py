# 에디터

from sys import stdin

st1 = list(input())
st2 = []
n = int(input())

for _ in range(n):
    command = list(stdin.readline().split())
    if command[0] == 'L' and st1:
        st2.append(st1.pop())
    elif command[0] == 'D' and st2:
        st1.append(st2.pop())
    elif command[0] == 'B' and st1:
        st1.pop()
    elif command[0] == 'P':
        st1.append(command[1])

st1.extend(reversed(st2))
print(''.join(st1))