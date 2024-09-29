from collections import deque
import sys
input = sys.stdin.readline

n = int(input()) # 명령의 수
a = list(map(int, input().split())) # 길이 n의 수열 
b = list(map(int, input().split())) # 길이 n의 수열
m = int(input())
c = list(map(int, input().split()))

queue = deque([])
for i in range (n):
    if a[i] == 0:
        queue.append(b[i])

for i in range(m):
    queue.appendleft(c[i])
    print(queue.pop(), end = ' ')