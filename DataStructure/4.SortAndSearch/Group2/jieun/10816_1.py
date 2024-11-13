from collections import Counter

n = int(input())
n_arr = list(map(int,input().split()))
m = int(input())
m_arr= list(map(int,input().split()))

count = Counter(n_arr)

for i in range(m):
    if m_arr[i] in count:
        print(count[m_arr[i]],end = " ")
    else:
        print(0, end = ' ')
