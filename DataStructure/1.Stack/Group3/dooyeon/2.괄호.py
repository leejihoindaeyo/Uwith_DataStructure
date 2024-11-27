num=int(input())
for i in range(num):
    stack=0
    temp=input()
    for j in range(len(temp)):
        if temp[j]=='(': stack+=1
        elif stack>0: stack-=1
        else: print('NO');stack=-1; break
    if stack>0: print('NO')
    elif stack==0:print('YES')