def insert_tree(depth, start, end, input, arr):
    if start >= end:
        return
    mid = (start + end) // 2
    arr[depth].append(input[mid])
    insert_tree(depth + 1, start, mid, input, arr)
    insert_tree(depth + 1, mid + 1, end, input, arr)

k = int(input())  
input_data = list(map(int, input().split())) 
arr = [[] for _ in range(k)]  

insert_tree(0, 0, len(input_data), input_data, arr)

for level in arr:
    print(" ".join(map(str, level)))