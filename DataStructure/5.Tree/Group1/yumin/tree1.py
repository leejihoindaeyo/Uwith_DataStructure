import sys
input = sys.stdin.readline

n = int(input())
tree = {}
for i in range(n):
    root, left, right = input().rstrip().split()
    tree[root] = [left, right]

def preorder(root): #전위
    if root != '.':
        print(root, end='') #루트
        preorder(tree[root][0]) #왼
        preorder(tree[root][1]) #오

def inorder(root): #중위
    if root != '.':
        inorder(tree[root][0]) #왼
        print(root, end='') #루트
        inorder(tree[root][1]) #오

def postorder(root): #후위
    if root != '.':
        postorder(tree[root][0]) #왼
        postorder(tree[root][1]) #오
        print(root, end='') #루트

preorder('A')
print()
inorder('A')
print()
postorder('A')