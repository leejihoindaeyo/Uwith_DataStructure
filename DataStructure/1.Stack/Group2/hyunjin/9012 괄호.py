import sys

t = int(input())

for _ in range(t):
    Parenthesis_String = input().rstrip()
    balance = 0
    Valid_Parenthesis_String = True

    for char in Parenthesis_String:
        if char == '(':
            balance += 1
        else:
            balance -= 1

        if balance < 0:
            Valid_Parenthesis_String = False
            break

    if balance != 0:
        Valid_Parenthesis_String = False

    if Valid_Parenthesis_String:
        print("YES")
    else:
        print("NO")


