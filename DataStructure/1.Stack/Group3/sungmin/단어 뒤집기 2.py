char = input() 
stack = []  # 문자를 입력받는 스택
tag = False  # 태그 안에 들어왔는지 확인해주는 용도

for ch in char:
    
    if ch == '<':
        while stack:
            print(stack.pop(), end='')
        print(ch, end='')
        tag = True
        
    elif ch == '>':
        print(ch, end='')
        tag = False
        
    else:
        if tag:
            print(ch, end='')
        else:
            if ch == ' ' or ch == '\n':
    
                while stack:
                    print(stack.pop(), end='')
                
                print(ch, end='')
            else:
            
                stack.append(ch)


while stack:
    print(stack.pop(), end='')

# 태그를 잘 확인하고 스택에 넣어주기
# 문자열 뒤집는건 스택을 이용하면 좋을듯함