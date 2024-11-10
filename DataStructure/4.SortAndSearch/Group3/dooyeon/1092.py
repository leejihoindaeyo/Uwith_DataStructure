def time_to_load(N, cranes, M, boxes):
    cranes.sort(reverse=True)
    boxes.sort(reverse=True)
    
    if boxes[0] > cranes[0]:
        return -1 
    
    time = 0
    while boxes:
        deleting = False
        for i,crane in enumerate(cranes):
            for j,box in enumerate(boxes):
                if box <= crane:
                    del boxes[j]
                    break
                if box == boxes[-1]:
                    deleting = True
            if deleting:
                cranes = cranes[0:i+1]
                break
        time += 1
    return time

N = int(input())
cranes = list(map(int, input().split()))
M = int(input())
boxes = list(map(int, input().split()))

print(time_to_load(N, cranes, M, boxes))