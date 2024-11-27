import sys
input = sys.stdin.readline

s = input().rstrip()
flag = False
word = ""
ans = ""

for i in s:
    if flag == False:
        if i == "<":
            flag = True
            word += i
        elif i == " ":
            ans += word + " "
            word = ""
        else:
            word = i + word


    else:
        word += i
        if i == ">":
            flag = False
            ans += word
            word = ""

print(ans + word)