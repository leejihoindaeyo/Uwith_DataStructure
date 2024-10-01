from collections import deque

def calc(num1, num2, cal):
    if cal == '-':
        return num1 - num2
    if cal == '+':
        return num1 + num2
    if cal == '*':
        return num1 * num2
    if cal == '/':
        return num1 // num2  
    return 0

str_input = input().strip() 
num = deque()
oper = deque()
temp = ""

for i in range(len(str_input)):
    if str_input[i] == '-' and i == 0:
        temp += '-'
        continue
    if str_input[i] in ['-', '+', '*', '/']:
        if temp:
            num.append(int(temp))
        temp = ""
        oper.append(str_input[i])
    else:
        temp += str_input[i]

if temp:
    num.append(int(temp))

while True:
    if len(num) == 1:
        print(num[0])
        break
    if (oper[0] in ['*', '/'] and oper[-1] in ['*', '/']):
        left_num = calc(num[0], num[1], oper[0])
        right_num = calc(num[-2], num[-1], oper[-1])
        if left_num >= right_num:
            num.popleft()
            num.popleft()
            num.appendleft(left_num)
            oper.popleft()
        else:
            num.pop()
            num.pop()
            num.append(right_num)
            oper.pop()
    elif (oper[0] in ['-', '+'] and oper[-1] in ['-', '+']):
        left_num = calc(num[0], num[1], oper[0])
        right_num = calc(num[-2], num[-1], oper[-1])
        if left_num >= right_num:
            num.popleft()
            num.popleft()
            num.appendleft(left_num)
            oper.popleft()
        else:
            num.pop()
            num.pop()
            num.append(right_num)
            oper.pop()
    elif (oper[0] in ['*', '/'] and oper[-1] in ['+', '-']):
        left_num = calc(num[0], num[1], oper[0])
        num.popleft()
        num.popleft()
        num.appendleft(left_num)
        oper.popleft()
    elif (oper[0] in ['-', '+'] and oper[-1] in ['*', '/']):
        right_num = calc(num[-2], num[-1], oper[-1])
        num.pop()
        num.pop()
        num.append(right_num)
        oper.pop()
