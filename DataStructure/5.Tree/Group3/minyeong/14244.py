n, m = map(int, input().split())
for i in range(n-m+1):
    print(i, i+1)

for i in range(m-2):
    print(1, n-m+2+i)