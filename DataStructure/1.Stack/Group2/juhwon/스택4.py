N = int(input())
ans = 0
for i in range(N):
    s = list(input().rstrip())
    stack = [False]
    for x in s:
        if stack[-1] == x:
            stack.pop()
        else:
            stack.append(x)
    if len(stack) == 1:
        ans+=1
print(ans)