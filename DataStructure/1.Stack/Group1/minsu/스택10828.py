import sys
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)  # 리스트의 append()를 이용해 스택에 요소 추가

    def pop(self):
        if not self.empty():
            return self.stack.pop()  # 리스트의 pop()을 이용해 스택에서 요소 제거 및 반환
        else:
            return -1  # 스택이 비어있으면 -1 반환

    def empty(self):
        if len(self.stack) == 0:
            return 1
        else:
            return 0

    def size(self):
        return len(self.stack)  # 스택의 크기 반환

    def top(self):
        if not self.empty():
            return self.stack[-1]  # 스택의 최상단 요소는 리스트의 마지막 요소
        else:
            return -1  # 스택이 비어있으면 -1 반환


ls = Stack()

n = int(sys.stdin.readline())  # 명령의 수

for i in range(n):
    command = sys.stdin.readline().split()
    
    if command[0] == "push":
        ls.push(int(command[1]))  # push 명령 시 숫자를 정수로 변환
    elif command[0] == "top":
        print(ls.top())  # top 명령어의 결과를 출력
    elif command[0] == "size":
        print(ls.size())  # size 명령어의 결과를 출력
    elif command[0] == "pop":
        print(ls.pop())  # pop 명령어의 결과를 출력
    elif command[0] == "empty":
        print(ls.empty())  # empty 명령어의 결과를 출력
