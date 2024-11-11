import sys
input = sys.stdin.readline

n = int(input())
budgets = list(map(int, input().split()))
m = int(input())
start = 0
end = max(budgets)

while start <= end:
    mid = (start + end) // 2
    total = 0

    for i in budgets:
        if i <= mid: #요청 예산이 상한액 이상이면 상한값을 더함
            total += i
        else: #요청 예산이 상한값보다 작으면 요청 예산을 더함
            total += mid

    if total <= m: #예산 총액이 최댓값(총 예산) 이하면 (구하려는 최종 값)
        start = mid + 1 #상한값 높여서 다시 탐색
        result = mid
    else: #예산 총액이 최댓값(총 예산)을 초과하면
        end = mid - 1 #상한값 낮춰서 다시 탐색

print(end)