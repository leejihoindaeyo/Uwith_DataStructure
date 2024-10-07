import sys
input = sys.stdin.read

data=input().splitlines()
left_stack = list(data[0])
right_stack = []  

m = int(data[1])
commands=data[2:]

for i in range(m):
    command = commands[i].split()
    order = command[0]
    
    if order == 'L':  # 커서를 왼쪽으로 이동
        if left_stack:
            right_stack.append(left_stack.pop())  # 왼->오

    elif order == 'D':  # 커서를 오른쪽으로 이동
        if right_stack:
            left_stack.append(right_stack.pop())  # 오->왼
    
    elif order == 'B':  #  왼쪽 문자 삭제
        if left_stack:
            left_stack.pop()  # 왼쪽 1개 제거

    elif order == 'P':  # 왼쪽에 문자 추가
        ch = command[1]
        left_stack.append(ch)  # 왼쪽 추가

left_stack.extend(reversed(right_stack))
print(''.join(left_stack))
