def dfs(num, li):
    li[num]  = -2
    for i in range(len(li)):
        if num == li[i]:
            dfs(i, li)
n = int(input())
li = list(map(int ,input().split()))
m = int(input())
count = 0

dfs(m, li)
count =0
for i in range(len(li)):
    if li[i]!=-2 and i not in li:
        count +=1
print(count)