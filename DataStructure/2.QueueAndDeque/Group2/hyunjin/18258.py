import sys

class Queue:
    def __init__(self):
        self._items = []
        self.first_idx = 0

    def push(self, X):
        self._items.append(X)

    def empty(self):
        if len(self._items) == self.first_idx:
            self._items = []
            self.first_idx = 0
            return 1
        return 0

    def pop(self):
        if len(self._items) > self.first_idx:
            self.first_idx += 1
            return self._items[self.first_idx - 1]
        return -1

    def size(self):
        return len(self._items) - self.first_idx

    def front(self):
        if len(self._items) > self.first_idx:
            return self._items[self.first_idx]
        return -1

    def back(self):
        if len(self._items) > self.first_idx:
            return self._items[-1]
        return -1

queue = Queue()
N = int(sys.stdin.readline())

for _ in range(N):
    order = sys.stdin.readline().rstrip()
    if "push" in order:
        __, num = order.split()
        queue.push(int(num))
    elif order == "front":
        print(queue.front())
    elif order == "back":
        print(queue.back())
    elif order == "pop":
        print(queue.pop())
    elif order == "size":
        print(queue.size())
    else:
        print(queue.empty())