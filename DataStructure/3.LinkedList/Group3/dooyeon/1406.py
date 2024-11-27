from collections import deque

s = input().strip()
m = int(input())
text = deque(s)
cursor = len(text)

for _ in range(m):
    order = input().split()
    if order[0] == 'L':
        if cursor > 0:
            cursor -= 1
    elif order[0] == 'D':
        if cursor < len(text):
            cursor += 1
    elif order[0] == 'B':
        if cursor > 0:
            cursor -= 1
            text.remove(text[cursor])
    elif order[0] == 'P':
        text.insert(cursor, order[1])
        cursor += 1

print(''.join(text))
