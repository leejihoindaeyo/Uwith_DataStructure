s = input()
temp = []
answer = []

for i in range(len(s)):
    if s[i] == '>':
        temp.append('>')
        answer.append(''.join(temp))
        temp = []
    elif s[i] == '<' and temp:
        temp.reverse()
        answer.append(''.join(temp))
        temp = [s[i]]
    elif s[i] == ' ' and '<' not in temp:
        temp.reverse()
        answer.append(''.join(temp))
        answer.append(' ')
        temp = []
    else:
        temp.append(s[i])

if temp:
    temp.reverse()
    answer.append(''.join(temp))

print(''.join(answer))