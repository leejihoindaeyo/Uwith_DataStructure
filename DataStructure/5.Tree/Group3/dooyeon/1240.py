from collections import deque

def bfs(start_node, target_node, num_nodes, adj_list):
    queue = deque()
    queue.append((start_node, 0))
    visited_nodes = [False] * (num_nodes + 1)
    visited_nodes[start_node] = True
    while queue:
        current_node, current_distance = queue.popleft()

        if current_node == target_node:
            return current_distance

        for neighbor_node, edge_length in adj_list[current_node]:
            if not visited_nodes[neighbor_node]:
                visited_nodes[neighbor_node] = True
                queue.append((neighbor_node, current_distance + edge_length))

num_nodes, num_queries = map(int, input().split())
adj_list = [[] for _ in range(num_nodes + 1)]

for _ in range(num_nodes - 1):
    node1, node2, length = map(int, input().split())
    adj_list[node1].append((node2, length))
    adj_list[node2].append((node1, length))

for _ in range(num_queries):
    start_node, target_node = map(int, input().split())
    print(bfs(start_node, target_node, num_nodes, adj_list))

