import sys
from collections import deque
input = sys.stdin.readline

form = list(input().rstrip())
nums = deque()
ops = deque()

def perform_op(n1, op, n2):  # 연산 구현
    if op == '+':
        return n1 + n2
    elif op == '*':
        return n1 * n2
    elif op == '-':
        return n1 - n2
    elif op == '/':
        if n1 * n2 >= 0:
            return n1 // n2
        else:
            return -(-n1 // n2)

num_string = ""
for i in form:
    if not i.isnumeric() and num_string:
        ops.append(i)
        if num_string:
            nums.append(int(num_string))
        num_string = ""
    else:
        num_string += i
if num_string:
    nums.append(int(num_string))

while ops:
    if ops[-1] in ('*', '/') and ops[0] in ('+', '-'):
        direction = "back"
    elif ops[0] in ('*', '/') and ops[-1] in ('+', '-'):
        direction = "front"
    elif (ops[0] in ('*', '/') and ops[-1] in ('*', '/')) or (ops[0] in ('+', '-') and ops[-1] in ('+', '-')):
        if perform_op(nums[0], ops[0], nums[1]) < perform_op(nums[-2], ops[-1], nums[-1]):
            direction = "back"
        else:
            direction = "front"
    else:
        direction = "front"  # 기본적으로 front 방향으로 설정

    if direction == "front":  # 앞부터 처리
        n1 = nums.popleft()
        n2 = nums.popleft()
        op = ops.popleft()
        nums.appendleft(perform_op(n1, op, n2))
    else:  # 뒤부터 처리
        n2 = nums.pop()
        n1 = nums.pop()
        op = ops.pop()
        nums.append(perform_op(n1, op, n2))

print(*nums, sep='')
