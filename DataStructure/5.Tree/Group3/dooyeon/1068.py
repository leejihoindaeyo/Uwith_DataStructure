from collections import defaultdict

def count_leaves(tree, root):
    if root == -1:
        return 0
    if not tree[root]:
        return 1
    count = 0
    for child in tree[root]:
        count += count_leaves(tree, child)
    return count

n = int(input())
parents = list(map(int, input().split()))
delete_node = int(input())

tree = defaultdict(list)
root = -1

for child, parent in enumerate(parents):
    if parent == -1:
        root = child
    else:
        tree[parent].append(child)

if delete_node == root:
    print(0)
else:
    for parent in tree:
        if delete_node in tree[parent]:
            tree[parent].remove(delete_node)
    print(count_leaves(tree, root))