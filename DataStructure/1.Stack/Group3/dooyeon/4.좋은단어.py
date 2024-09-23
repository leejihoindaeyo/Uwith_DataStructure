N = int(input())
answer = 0
for i in range(N):
    temp = input()
    stack = []
    for letter in temp:
        if stack and stack[-1] == letter:
            stack.pop()
        else:
            stack.append(letter)
    if not stack:
        answer += 1
print(answer)