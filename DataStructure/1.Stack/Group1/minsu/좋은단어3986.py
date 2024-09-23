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
        
    def empty(self):
        return len(self.stack) == 0
    
    def size(self):
        return len(self.stack)
    
    def display(self, ind):
        return self.stack[ind]
    
n = int(input())
result = 0
for _ in range(n):
    s = input()
    ls = stack()
    for j in range(len(s)):
        # 스택이 비어있으면 추가를 해줌 아닐경우에는 비교를 해줌
        if ls.size() == 0: ls.push(s[j])
        else: # 마지막문자와 비교하여 같으면 pop(빼줌) 다를경우에는 스택에 넣어줌
            if ls.display(-1) == s[j]: ls.pop()
            else: ls.push(s[j])
    if ls.size() == 0 : result += 1 # 반복문을 순회하여 스택에 pop을 이용해서 다 없어진 경우만 결과에 1을 더해줌
print(result)