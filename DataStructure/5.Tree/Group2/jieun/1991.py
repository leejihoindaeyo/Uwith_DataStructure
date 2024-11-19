

n = int(input())
tree = {}

for i in range(n):
    root, left, right = map(str,input().split())
    tree[root] = left,right

# 전위순회
def preorder(t): 
    if t != '.':
        print(t,end= ' ') # 루트
        preorder(tree[t][0]) # 왼쪽
        preorder(tree[t][1]) # 오른쪽

# 중위순회
def inorder(t):
    if t != '.':
        inorder(tree[t][0]) # 왼쪽
        print(t,end=' ') # 루트
        inorder(tree[t][1]) # 오른쪽

# 후위순회        
def postorder(t):
    if t != '.':
        postorder(tree[t][0]) # 왼쪽
        postorder(tree[t][1])  # 오른쪽
        print(t,end = " ") # 루트

preorder('A')
print("")
inorder("A")
print("")
postorder("A")




