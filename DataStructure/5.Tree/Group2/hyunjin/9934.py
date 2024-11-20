import sys

input = sys.stdin.readline

K = int(input())
nums = list(map(int, input().split()))
nums.reverse()
tree = [0 for _ in range(2 ** K)]

def make_tree(tree, nums, root):
    if root < 1 or 2 ** K <= root or tree[root] != 0: return
    make_tree(tree, nums, 2 * root)
    tree[root] = nums.pop()
    make_tree(tree, nums, 2 * root + 1)

make_tree(tree, nums, 1)
i = 1
while i < 2 ** K:
    for j in range(i, i * 2):
        print(tree[j], end=' ')
    print()
    i *= 2
