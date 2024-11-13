
N = int(input())
C= list(map(int, input().split()))

M = int(input())
B = list(map(int, input().split()))

C.sort(key=lambda x:-x)
B.sort(key=lambda x:-x)

sol=0
count=0
visited=[0 for _ in range(M)]
if B[0] > C[0]:
    print(-1)
else:
    while count<M:
        for crain in range(N):              
            for box in range(len(B)): 
                if not visited[box] and B[box] <= C[crain] :
                    
                    count+=1
                    visited[box]=1
                    
                    break
        sol+=1
        
    print(sol)