import sys

class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)  # 스택에 괄호 추가

    def pop(self):
        if not self.empty():
            return self.stack.pop()  # 스택에서 요소 제거
        else:
            return None  # 스택이 비어있을 경우 None 반환

    def empty(self):
        return len(self.stack) == 0  # 스택이 비어있는지 확인

def check_parentheses(s):
    ls = Stack()
    for char in s:
        if char == "(":
            ls.push(char)
        elif char == ")":
            if ls.empty():
                return "NO"
            ls.pop()

    # 모든 괄호 쌍이 맞으면 스택은 비어 있어야 함
    if ls.empty():
        return "YES"
    else:
        return "NO"

n = int(sys.stdin.readline())  # 명령의 수

for _ in range(n):
    command = sys.stdin.readline().strip()  # 한 줄의 괄호 문자열을 입력받음
    result = check_parentheses(command)
    print(result)