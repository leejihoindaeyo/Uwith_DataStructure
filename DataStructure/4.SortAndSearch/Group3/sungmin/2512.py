# 2512번 예산

N = int(input())
nums = list(map(int,input().split()))
Maximum = int(input())

low,high = 0 , max(nums)

while low <= high:
    mid = (low+high) // 2
    new_nums = [min(num,mid) for num in nums]
    res = sum(new_nums)
    
    if res <= Maximum :
        result = mid
        low = mid+1
    
    else :
        high = mid -1
        
    
print(result)