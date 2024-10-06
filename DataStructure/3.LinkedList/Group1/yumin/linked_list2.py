while True:
    s = input()
    if s == '.':
        break;

    stack = []
    balance = True

    for i in s:
        if i == '(' or i == '[':
            stack.append(i)
        elif i == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                balance = False
                break
        elif i == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                balance = False
                break

    if balance and not stack: #균형이 맞고 (balance가 True이고) stack이 비어있으면
        print('yes')
    else:
        print('no')