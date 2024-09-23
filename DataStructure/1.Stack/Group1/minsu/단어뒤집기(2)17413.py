import sys

class Stack:
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
        if len(self.stack) == 0:
            return 1
        else:
            return 0


sentence = sys.stdin.readline().strip() + ' ' #문자열을 입력받음 양쪽 끝에 공백을 .strip()을 이용하여 지워줌 공백은 마지막 단어도 같이 구분해주기위해
ls = Stack() # 스택 객체
result = ''
cnt = 0

for i in sentence:
    if i == '<':  # 태그 시작
        cnt = 1 # 태그 안에 있음
        while not ls.empty():  # 태그 시작 전 쌓인 스택 비우기 (역순으로 결과에 추가)
            result += ls.pop()
        result += i  # '<'는 그대로 추가
    elif i == '>':  # 태그 끝
        cnt = 0 #태그 밖을 나왔음을 의미
        result += i  # '>'도 그대로 추가
    elif cnt == 1:  # 태그 내부에서는 그대로 추가
        result += i
    elif i == ' ':  # 공백을 만나면 스택의 내용을 역순으로 추가
        while not ls.empty():
            result += ls.pop()
        result += ' '  # 공백 추가
    else:  # 태그 외부의 문자들은 스택에 쌓아둠
        ls.push(i)

print(result)