N = int(input())

for _ in range(N):
    
    char = input()
    stack = []  

    for i in range(len(char)):
        
        if len(stack) == 0:
            stack.append(char[i])
            
        else:
            
            if stack[-1] == '(' and char[i] == ')': # 짝이 맞을 때
                stack.pop()
                
            else:
                stack.append(char[i])


    if len(stack) == 0: # 짝이 다 맞았을 때 
        print("YES")
        
    else:
        print("NO")

# 스택에 잠시 넣어두고 짝이 맞으면 다시 빼주는 느낌 