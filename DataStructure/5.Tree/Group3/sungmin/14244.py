n,m = map(int,input().split())

for i in range(n-1):
    if i < n-m :
        print(f"{i} {i+1}")
    else :
        print(f"{n-m} {i+1}")
        
    