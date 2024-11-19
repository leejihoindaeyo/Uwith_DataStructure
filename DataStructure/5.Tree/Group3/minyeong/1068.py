import sys

# 리프 노드 찾는 함수
def find_leaf(node):
    global answer, checked, delete_node

    # 현재 노드가 삭제한 노드라면 종료
    if node == delete_node:
        return

    # 현재 노드에 연결된 다른 노드가 없다면 해당 노드가 리프 노드
    if len(graph[node]) == 0:
        answer += 1
        return

    # 현재 노드에 연결된 다른 노드 탐색
    for nxt in graph[node]:
        if checked[nxt]:
            continue

        checked[nxt] = True
        find_leaf(nxt)


# 노드 개수
N = int(sys.stdin.readline().rstrip())
# 입력 받은 정보
tree = list(map(int, sys.stdin.readline().rstrip().split()))

root = -1 # 루트 노드 번호
# 트리 구조 저장할 그래프
graph = [[] for _ in range(N + 1)]
for node in range(N):
    p = tree[node]

    # 루트 노드 번호 찾기
    if p == -1:
        root = node
        continue

    graph[p].append(node)

# 삭제할 노드 번호
delete_node = int(sys.stdin.readline().rstrip())
# 삭제할 노드 번호는 삭제해줌
graph[delete_node] = []

# 다른 그래프에 저장되어 있는 삭제 노드 번호를 삭제 해 줌
for g in graph:
    if delete_node in g:
        g.remove(delete_node)

checked = [False for _ in range(N)]
answer = 0

checked[root] = True
# 리프 노드 찾기
find_leaf(root)

print(answer)