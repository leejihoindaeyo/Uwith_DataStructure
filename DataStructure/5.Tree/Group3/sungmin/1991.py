class TNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def preorder(n):
    if n is not None:
        print(n.data, end='')
        preorder(n.left)
        preorder(n.right)

def inorder(n):
    if n is not None:
        inorder(n.left)
        print(n.data, end='')
        inorder(n.right)

def postorder(n):
    if n is not None:
        postorder(n.left)
        postorder(n.right)
        print(n.data, end='')

def build():
    n = int(input())
    nodes = {}

    for _ in range(n):
        parent, left, right = input().split()
        
        if parent not in nodes:
            nodes[parent] = TNode(parent)

        if left != '.':
            if left not in nodes:
                nodes[left] = TNode(left)
            nodes[parent].left = nodes[left]
            
        if right != '.':
            if right not in nodes:
                nodes[right] = TNode(right)
            nodes[parent].right = nodes[right]

    root_key = list(nodes.keys())[0]
    return nodes[root_key]

root = build()
    
preorder(root)
print() 
inorder(root)
print()  
postorder(root)
print()  
