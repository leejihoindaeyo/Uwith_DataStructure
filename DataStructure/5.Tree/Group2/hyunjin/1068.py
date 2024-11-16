import sys
input = sys.stdin.readline

def dfs(K: int) -> None:
    tree[K] = -2
    for i in range(N):
        if K == tree[i]:
            dfs(i)

if __name__ == "__main__":
    N = int(input())
    tree = list(map(int, input().split()))
    K = int(input())

    dfs(K)

    count = 0
    for i in range(len(tree)):
        if tree[i] != -2 and i not in tree:
            count +=1
    print(count)