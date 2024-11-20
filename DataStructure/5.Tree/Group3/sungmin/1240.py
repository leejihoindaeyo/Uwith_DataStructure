class TNode:
    def __init__(self, data):
        self.data = data
        self.children = [] 
        self.distances = []
        
def buildTree(parents,distances):
    n = len(parents)
    nodes = [TNode(i) for i in range(n)]
    
    for child, parent in enumerate(parents):
        nodes[parent].children.append(nodes[child])
        nodes[parent].distances.append(distances[child])
    
    return nodes

def dfs(current,target,current_dist):
    if current == target:
        return current_dist
    
    for i, child in enumerate(current.children):
        dist = dfs(child, target, current_dist + current.distances[i])
        if dist != -1:
            return dist
        
    return -1


