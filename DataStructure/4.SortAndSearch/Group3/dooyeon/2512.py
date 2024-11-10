N = int(input()) 
budgets = list(map(int, input().split())) 
M = int(input()) 

low, high = 0, max(budgets)
result = 0

while low <= high:
    mid = (low + high) // 2 
    total = 0
    
    for budget in budgets:
        total += min(budget, mid)
    if total <= M:
        result = mid
        low = mid + 1
    else:
        high = mid - 1

print(result)