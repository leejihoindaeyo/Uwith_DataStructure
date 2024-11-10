import sys

n = int(input())
word = list(map(int, sys.stdin.readline().split()))
n1 = int(input())

# 시간초과,,,
"""

large = max(word)
w = True
result = sum(word)

while n1 <= result:
    result = 0
    for i in word:
        if large <= i:
            result += large
        else:
            result += i
    large -= 1
    w = False
if w:
    print(f"{large}")
else:
    print(f"{large+1}")
"""

# 시간 단축을 위해 이분탐색 이용
start = 0
end = max(word)

while start <= end:
    mid = (start+end)//2
    result = 0
    for i in word:
        if i >= mid:
            result += mid
        else:
            result += i
    if result <= n1:
        start = mid+1
    else:
        end = mid - 1
print(end)
            
# large 계속 -1
# large 보다 작으면 그대로 더함
# large 보다 크면 large 더하기



