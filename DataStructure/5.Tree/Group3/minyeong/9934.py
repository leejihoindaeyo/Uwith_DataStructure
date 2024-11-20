
import sys
input = sys.stdin.readline

k = int(input())
squence = list(map(int, input().split()))

trees = [[] for _ in range(k)]

#완전 이진 트리이니까 각 층의 노드는 중간의 값
def binary_tree(array, depth):
    mid_index = len(array) // 2
    trees[depth].append(array[mid_index])
    #만약 input_array가 길이가 1이라면 해당 재귀 종료
    if len(array) == 1:
        return
    #왼쪽 노드부터 먼저 추가 되어야 하니까
    binary_tree(array[:mid_index], depth + 1)
    binary_tree(array[mid_index+1:], depth + 1)



binary_tree(squence, 0)
for tree in trees:
    print(*tree)