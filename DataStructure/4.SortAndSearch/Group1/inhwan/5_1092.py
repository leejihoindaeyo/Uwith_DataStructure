n = int(input())
max_li = list(map(int, input().split()))
m = int(input())
box_li = list(map(int, input().split()))

max_li.sort(reverse=True)
box_li.sort(reverse=True)

num =0
if box_li[0] > max_li[0]: num = -1
else:
    while box_li:
        for i in max_li:
            if box_li and i < box_li[-1]:
                continue
            for j in box_li:
                if i >= j:
                    box_li.remove(j)
                    break
        num+=1
print(num)