import sys

class stack:
    def __init__(self):
        self.stack = []
    
    def push(self, item):
        self.stack.append(item)
    
    def pop(self):
        if not self.empty():
            return self.stack.pop()
        else:
            return None
    
    def size(self):
        return len(self.stack)
    
    def empty(self):
        return len(self.stack) == 0
    
    def display(self, ind):
        return self.stack[ind]
    

# 우선순위 연산자 처리 함수
def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    return 0

# 중위 연산자를 후위 연산자로 변환하는 함수
def change(exp):
    ls = stack()
    result = []
    
    for char in exp:
        # 피연산자 (대문자 알파벳)는 결과 리스트에 추가
        if char.isalpha() and char.isupper():
            result.append(char)
        # 왼쪽 괄호는 스택에 추가
        elif char == '(':
            ls.push(char)
        # 오른쪽 괄호는 '('를 만날 때까지 스택에서 팝
        elif char == ')':
            while not ls.empty() and ls.display(-1) != '(':
                result.append(ls.pop())
            ls.pop()  # '(' 제거
        # 연산자일 경우
        else:
            while not ls.empty() and precedence(ls.display(-1)) >= precedence(char):
                result.append(ls.pop())
            ls.push(char)
    
    # 남아있는 연산자를 모두 팝
    while not ls.empty():
        result.append(ls.pop())
    
    # 리스트를 문자열로 변환해서 반환
    return ''.join(result)

# 입력 받기
s = sys.stdin.readline().strip()

# 후위 표기식 출력
print(change(s))