def check(op): # 연산자의 우선순위 판별기 
    if op == '(':
        return 0
    elif op == '+' or op == '-':
        return 1
    elif op == '*' or op == '/':
        return 2
    return -1

def changer(expression):
    result = []
    stack = []
    
    for char in expression:
        
        if char.isalpha():  # 피연산자 (A, B, C 등)
            result.append(char)
            
        elif char == '(':   # 왼쪽 괄호는 스택에 넣음
            stack.append(char)
            
        elif char == ')':   # 오른쪽 괄호는 왼쪽 괄호를 만날 때까지 팝
            
            while stack and stack[-1] != '(':
                result.append(stack.pop())
                
            stack.pop()  # 왼쪽 괄호 제거
            
        else:  # 연산자
            
            while stack and check(stack[-1]) >= check(char):
                result.append(stack.pop())
                
            stack.append(char)
    
    # 스택에 남아있는 연산자 모두 출력
    while stack:
        result.append(stack.pop())
    
    return ''.join(result)

expression = input()

print(changer(expression))


# 연산자의 위치만 신경써주면 되는 문제
# 스택에 잠시 연산자를 옮겼다가 우선순위에 따라 결과값으로 옮겨주기