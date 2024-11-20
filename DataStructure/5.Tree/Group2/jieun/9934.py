
n = int(input())
tree = list(map(int,input().split()))
bin_tree = [[] for _ in range(n)]

def make_Tree(arr,x):
    mid = (len(arr)//2)
    bin_tree[x].append(arr[mid])
    if len(arr) == 1:
        return 
    make_Tree(arr[:mid],x+1)
    make_Tree(arr[mid+1:],x+1)

make_Tree(tree,0)
for i in range(n):
    print()

