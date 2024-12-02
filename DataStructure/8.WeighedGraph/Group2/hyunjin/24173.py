import sys

COUNT = 0
exchange_list = []

def heapify(a_list,root,n):
    global K
    global COUNT
    child = root*2 + 1
    while child < n:
        if child + 1 < n:
            if a_list[child] > a_list[child+1]:
                child += 1
        if a_list[root] > a_list[child]:
            COUNT += 1
            if COUNT == K:
                exchange_list.append([a_list[child],a_list[root]])
                return
            a_list[root],a_list[child] = a_list[child],a_list[root]
            root = child
            child = root * 2 + 1
        else:
            break
    return a_list

def heap_sort(a_list):
    global K
    global COUNT
    n = len(a_list)
    root = int((n-1)/2)
    global exchange_list
    while root >= 0:
        a_list = heapify(a_list,root,n)
        if COUNT == K:
            return
        root += -1

    i = n-1

    while i >= 1 :
        COUNT += 1
        if COUNT == K:
            exchange_list.append([a_list[0], a_list[i]])
            return
        a_list[0],a_list[i] = a_list[i],a_list[0]
        a_list = heapify(a_list,0,i)
        if COUNT == K:
            return
        i += -1

N, K = map(int, input().split())
a_list =  list(map(int, input().split()))

heap_sort(a_list)

if K > COUNT:
    print(-1)
else:
    print(' '.join(list(map(str,exchange_list[0]))))