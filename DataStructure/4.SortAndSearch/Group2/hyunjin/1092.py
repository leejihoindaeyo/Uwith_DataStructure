import sys

n = int(input())
crane = list(map(int, input().split()))
m = int(input())
boxes = list(map(int, input().split()))
crane.sort(reverse=True)
boxes.sort(reverse=True)
minute = 0

if crane[0] < boxes[0]:
    print(-1)
    sys.exit()

while boxes:
    temp = []
    for cra in crane:
        for box in boxes:
            if cra >= box:
                boxes.remove(box)
                break
    minute += 1

print(minute)