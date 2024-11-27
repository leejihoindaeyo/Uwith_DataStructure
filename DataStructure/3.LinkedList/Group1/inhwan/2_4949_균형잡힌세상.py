def is_balance(s):
    stack = []
    for ch in s:
        if ch == '(' or ch == '[':
            stack.append(ch)
        elif ch == ')':
            if not stack or stack[-1] != '(': #C++ :stack.top() == stack[-1]
                return False
            stack.pop()
        elif ch == ']':
            if not stack or stack[-1] != '[':
                return False
            stack.pop()

    return not stack

while True:
    s=input().rstrip()
    if s == '.':
        break
    if is_balance(s):
        print("yes")
    else:
        print("no")