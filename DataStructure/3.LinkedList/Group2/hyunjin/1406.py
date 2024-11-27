import sys
input = sys.stdin.readline
s = list(input().rstrip())
c = []

for _ in range(int(input())):
    command = input().rstrip()
    if command == "L":
        if s:
            c.append(s.pop())
    elif command == "D":
        if c:
            s.append(c.pop())
    elif command == "B":
        if s:
            s.pop()
    else:
        _,b = command.split()
        s.append(b)
s += c[::-1]
print(*s,sep="")