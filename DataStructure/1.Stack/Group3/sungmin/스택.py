import sys #시간 부족 문제 해결

n = int(sys.stdin.readline()) # 반복 횟수 입력 받음

stack=[]  # 리스트로 스택을 구현함

for _ in range(n):
    
    command = sys.stdin.readline().split() # push의 경우에는 변수 2개가 들어오기 때문에 .split()

    if command[0]=='push':
        
        stack.append(command[1])
        
    elif command[0]=='pop':
        
        if len(stack)==0:
            print(-1)
        
        else:
            print(stack.pop())
    
    elif command[0] == 'size':
        
        print(len(stack))
        
    elif command[0] == 'empty':
       
        if len(stack)==0:
            print(1)
        
        else:
            print(0)
    
    elif command[0] == 'top':
        
        if len(stack)==0:
            print(-1)
        
        else:
            print(stack[-1])
        

