import sys

n = int(input())
c = list(map(int,input().split()))
box_num = int(input())
box = list(map(int,input().split()))

c.sort(reverse=True)
box.sort(reverse=True)

count = 0

if c[0] < box[0]:
    count = -1

else: 
    while box:
        for i in c:
            if box and i <box[-1]:
                continue
            for b in box:
                if i >= b:
                    box.remove(b)
                    break
        count += 1
print(count)
