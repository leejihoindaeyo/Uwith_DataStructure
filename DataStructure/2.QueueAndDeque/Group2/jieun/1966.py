# 프린터 큐


A = int(input())
for _ in range(A):
    N,M = map(int, input().split())
    lis = list(map(int,input().split()))
    num = 1

    while lis:
        if lis[0] < max(lis):
            lis.append(lis.pop(0))
            M = (M - 1) % len(lis)
        else:
            if M == 0:
                print(num)
                break
            else:
                lis.pop(0)
                M -= 1
                num += 1


