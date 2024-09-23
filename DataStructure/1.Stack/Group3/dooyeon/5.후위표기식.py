equation = input()
temp,answer = [],''
for i in equation:
    if i == '(': temp.append(i)
    elif i == ')':
        while temp and temp[-1] != '(':
            answer += temp.pop()
        temp.pop()
    elif i == '*' or i == '/':
        while temp and (temp[-1] == '*' or temp[-1] == '/'):
            answer += temp.pop()
        temp.append(i)
    elif i == '+' or i == '-':
        while temp and temp[-1] != '(':
            answer += temp.pop()
        temp.append(i)
    else: answer += i        
while temp: answer += temp.pop()
print(answer)