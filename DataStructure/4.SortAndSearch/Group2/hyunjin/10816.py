N = int(input())
card = list(map(int, input().split()))
M = int(input())
saguen = list(map(int, input().split()))

card.sort()

for i in range(M):

    s = 0
    e = N - 1
    ans_1 = 0
    while s <= e:

        mid = (s + e) // 2

        if card[mid] == saguen[i]:
            ans_1 = mid
            e = mid - 1
        elif card[mid] > saguen[i]:
            e = mid - 1
        else:
            s = mid + 1

    s = 0
    e = N - 1
    ans_2 = 0
    while s <= e:

        mid = (s + e) // 2

        if card[mid] == saguen[i]:
            ans_2 = mid
            s = mid + 1
        elif card[mid] > saguen[i]:
            e = mid - 1
        else:
            s = mid + 1

    if ans_1 == 0 and ans_2 == 0:
        print(0, end=" ")
    else:
        print(ans_2 - ans_1 + 1, end=" ")