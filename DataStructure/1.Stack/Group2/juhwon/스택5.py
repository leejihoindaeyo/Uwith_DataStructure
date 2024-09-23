exp = input()
stack = []

prio = {'*': 1, '/': 1, '+': 2, '-':2, '(':3}
for e in exp:
    if e == '(':
        stack.append(e)
    elif e == ')':
        while 1:
            if stack[-1] == '(':
                stack.pop()
                break
            print(stack.pop(), end = '')
    elif e in prio:
        if not stack:
            stack.append(e)
        else:
            while 1:
                if prio[e] >= prio[stack[-1]]:
                    print(stack.pop(), end= '')
                else:
                    stack.append(e)
                    break
                if not stack:
                    stack.append(e)
                    break
    else:
        print(e, end = '')

while stack:
    print(stack.pop(), end = '')

print('')