import sys

# �Է� ó��
N = int(sys.stdin.readline().strip())
tree = list(map(int, sys.stdin.readline().split()))

def Tree(nodes, level=0, levels=None):
    if not nodes:
        return

    # ��Ʈ�� �߰� ��
    mid = len(nodes) // 2
    root = nodes[mid]

    # �������� ����
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
