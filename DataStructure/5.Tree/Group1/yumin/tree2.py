import sys

k = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
levels = [[] for i in range(k)] #트리의 레벨별로 노드를 저장하기 위한 이중 리스트

def seperation(arr, depth):
    if len(arr) == 1: #노드가 하나일 때
        levels[depth].extend(arr) #해당 노드가 루트
        return

    mid = len(arr) // 2

    levels[depth].append(arr[mid]) #리스트의 중앙값이 루트
    seperation(arr[:mid], depth + 1) #왼쪽 자식 노드 처리
    seperation(arr[mid + 1:], depth + 1) #오른쪽 자식 노드 처리

seperation(arr, 0)

for level in levels:
    for i in level:
        print(i, end= " ")
    print()

