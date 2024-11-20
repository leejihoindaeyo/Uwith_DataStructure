class TNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
        
def build_tree(li):
    if not li:
        return None
    
    mid = len(li) // 2
    root = TNode(li[mid])
    
    root.left = build_tree(li[:mid])
    root.right = build_tree(li[mid+1:])
    
    return root

def print_by_level(root):
    if not root:
        return 
    
    current = [root]
    level = 0
    
    while current :
        next_level = []
        
        for node in current:
            print(node.data, end=' ')
            
            if node.left:
                next_level.append(node.left)
                
            if node.right:
                next_level.append(node.right)
                
        current = next_level
        level += 1
        print()
        

K = int(input())
li = list(map(int,input().split()))

print_by_level(build_tree(li))    
                
                