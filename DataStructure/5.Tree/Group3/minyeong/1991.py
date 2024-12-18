node = int(input())
node_graph = {i:[] for i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}

#트리를 딕셔너리로 생성
for _ in range(node):
    node, left, right = map(str, input().split())
    node_graph[node] += [left, right]

#전위순회
def preorder(node_graph, root):
    stack = [root]
    result = ''

    while stack:
        node = stack.pop()
        result += node

        if node_graph[node][1] != '.':
            stack.append(node_graph[node][1])
            
        if node_graph[node][0] != '.':
            stack.append(node_graph[node][0])
            
    return result


#중위순회
def inorder(node_graph, root):
    stack = [root]
    result = ''
    
    while stack:
        if node_graph[stack[-1]][0] != '.' and node_graph[stack[-1]][0] not in result:
            stack.append(node_graph[stack[-1]][0])
            
        elif stack[-1] in result:
            stack.append(node_graph[stack[-1]][1])
            
        else:
            node = stack.pop()
            result += node
            if node_graph[node][1] != '.':
                stack.append(node_graph[node][1])
                
    return result

#후위순회
def postorder(node_graph, root):
    stack = [root]
    result = ''
    
    while stack:
        if node_graph[stack[-1]][0] != '.' and node_graph[stack[-1]][0] not in result:
            stack.append(node_graph[stack[-1]][0])
            
        elif node_graph[stack[-1]][1] == '.' or node_graph[stack[-1]][1] in result:
            result += stack.pop()
            
        else:
            stack.append(node_graph[stack[-1]][1])
            
    return result


print(preorder(node_graph, "A"))
print(inorder(node_graph, "A"))
print(postorder(node_graph, "A"))