from sys import stdin

left = list(input())
right = []

for i in range(int(input())) :
    com = list(stdin.readline().split())
    if com[0] == 'L' and len(left) != 0:
        right.append(left.pop()) #왼쪽에 있는 top을 오른쪽에 더하고 지움
    elif com[0] == 'D' and len(right) != 0:
        left.append(right.pop()) # 오른쪽에 있는 top을 왼쪽에 더하고 지움
    elif com[0] == 'B' and len(left) != 0:
        left.pop()
    elif com[0] == 'P':
        left.append(com[1])

ans = left + right[::-1]
print(''.join(ans))