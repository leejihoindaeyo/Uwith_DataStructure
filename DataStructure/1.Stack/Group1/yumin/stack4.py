n = int(input())
ans = 0

for i in range(n):
    stack = []
    for j in input():
        if len(stack) == 0:
            stack.append(j)
        else:
            if j == "A":
                if stack[-1] == "A":
                    stack.pop()
                elif stack[-1] == "B":
                    stack.append(j)
            elif j == "B":
                if stack[-1] == "B":
                    stack.pop()
                elif stack[-1] == "A":
                    stack.append(j)
    if len(stack) == 0:
        ans += 1

print(ans)