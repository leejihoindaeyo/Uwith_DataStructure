n = int(input()) 
count = 0 # 정답 갯수

for _ in range(n):
    string = str(input().strip())
    stack = []
    
    for i in range(len(string)):
        if stack and stack[-1] == string[i]: # 스택의 앞과 뒤가 같은 문자열일 때 
            stack.pop()
            
        else: 
            stack.append(string[i])
            
        if not stack: # 짝이 다 맞아서 스택이 비면 좋은 단어임
            count += 1


# 괄호문제와 유사한 느낌 문제 이해가 더 어려웠음 