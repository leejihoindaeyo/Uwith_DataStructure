class TNode:
    def __init__(self,data):
        self.data = data
        self.children = []
        
def build_tree(li):
    nodes = [TNode(i) for i in range(len(li))]
    root = None
    
    for child, parent in enumerate(li):
        if parent == -1 :
            root = nodes[child]
        
        else :
            nodes[parent].children.append(nodes[child])
        
    return root

def delete_node(root,target):
    
    if root.data == target :
        return None
    
    delete_func(root,target)
    return root

def delete_func(node, target, parent=None):

    if node is None:
        return False
    
    if node.data == target:
        if parent:
            parent.children = [child for child in parent.children if child.data != target]
        return True
            
    for child in node.children :
        if delete_func(child, target, node):
            return True
        
    return False

def count_leaf(node):
    
    if node is None:
        return 0
    
    if not node.children:
        return 1
    
    cnt = 0

    for child in node.children:
        cnt += count_leaf(child)
    
    return cnt

N = int(input())
li = list(map(int,input().split()))
target = int(input())

root = build_tree(li)
delete_node(root,target)
res = count_leaf(root)

print(res)