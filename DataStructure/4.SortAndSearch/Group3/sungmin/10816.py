# 10816번 숫자 카드 2

N = int(input())
dic = {}

nums = map(int, input().split())
for _ in range(N):
    for num in nums:
        if num not in dic:
            dic[num] = 1
        else:
            dic[num] += 1

M = int(input())
nums = map(int, input().split())

for _ in range(M):
    
    for num in nums:
        if num in dic:
            print(dic[num],end=' ')
        else:
            print(0,end=' ')
            
            
