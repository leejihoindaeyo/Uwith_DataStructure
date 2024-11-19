import sys

# 입력 처리
N = int(sys.stdin.readline().strip())
tree = list(map(int, sys.stdin.readline().split()))

def Tree(nodes, level=0, levels=None):
    if not nodes:
        return

    # 루트는 중간 값
    mid = len(nodes) // 2
    root = nodes[mid]

    # 레벨별로 저장
    if levels is None:
        levels = []
    if len(levels) <= level:
        levels.append([])
    levels[level].append(root)

    Tree(nodes[:mid], level + 1, levels)
    Tree(nodes[mid + 1:], level + 1, levels)

    return levels

levels = Tree(tree)

for level in levels:
    print(" ".join(map(str, level)))
