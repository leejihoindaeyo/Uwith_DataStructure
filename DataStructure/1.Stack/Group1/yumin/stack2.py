n = int(input())

for i in range(n):
    stack = []
    PS = input()

    for i in PS:
        if i == '(':
            stack.append(i)
        elif i == ')':
            if len(stack) == 0:
                print("NO")
                break
            else:
                stack.pop()

    else:
        if len(stack) == 0:
            print("YES")
        else:
            print("NO")