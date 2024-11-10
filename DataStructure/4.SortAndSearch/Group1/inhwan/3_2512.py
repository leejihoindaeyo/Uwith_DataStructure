n = int(input())
li = list(map(int, input().split()))
m = int(input())
start=0 
end = max(li) #가장 큰수

while start<=end:
    mid = (start+end) //2  #이진탐색으로 최댓값 찾기
    sum = 0
    for i in li:
        if i <= mid:  #원소 <= mid 
            sum += i   #합에 원소 추가
        else:           #원소 > mid
            sum +=mid  #합에 mid 추가

    if sum <= m: 
        start = mid + 1  
    else:
        end = mid -1

print(end)