import sys
from collections import deque
class Queue: # 선입선출
    def __init__(self):
        self.queue = deque()  # 큐를 리스트로 초기화

    # 정수 item을 큐에 넣는 함수
    def push(self, item):
        self.queue.append(item)

    # 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력, 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력
    def pop(self):
        if not self.empty():
            return self.queue.popleft()  # 리스트의 첫 번째 요소 제거
        else:
            return -1  # 큐가 비었으면 -1 반환

    # 큐에 들어있는 정수의 개수를 반환
    def size(self):
        return len(self.queue)

    # 큐가 비어있으면 1, 아니면 0 반환
    def empty(self):
        return 1 if len(self.queue) == 0 else 0

    # 큐의 가장 앞에 있는 정수를 출력, 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력
    def front(self):
        if not self.empty():
            return self.queue[0]
        else:
            return -1  # 큐가 비었으면 -1 반환

    # 큐의 가장 뒤에 있는 정수를 출력, 만약 큐에 들어있는 정수가 없는 경우에는 -1을 반환
    def back(self):
        if not self.empty():
            return self.queue[-1]
        else:
            return -1  # 큐가 비었으면 -1 반환

ls = Queue()
n = int(sys.stdin.readline()) # 명령의 수

for i in range(n):
    command = sys.stdin.readline().split()

    if (command[0] == "push"):
        ls.push(int(command[1]))
        
    elif (command[0] == "front"):
        print(ls.front())
    elif (command[0] == "back"):
        print(ls.back())
    elif (command[0] == "size"):
        print(ls.size())
    elif (command[0] == "empty"):
        print(ls.empty())
    else:
        print(ls.pop())
    
