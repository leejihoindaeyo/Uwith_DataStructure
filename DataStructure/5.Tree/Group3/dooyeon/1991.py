class BinaryTree:
    def __init__(self):
        self.tree = {}

    def add_node(self, parent, left, right):
        self.tree[parent] = (left, right)

    def preorder(self, node):
        if node == '.':
            return ''
        left, right = self.tree[node]
        return node + self.preorder(left) + self.preorder(right)

    def inorder(self, node):
        if node == '.':
            return ''
        left, right = self.tree[node]
        return self.inorder(left) + node + self.inorder(right)

    def postorder(self, node):
        if node == '.':
            return ''
        left, right = self.tree[node]
        return self.postorder(left) + self.postorder(right) + node

n = int(input())
binary_tree = BinaryTree()

for i in range(n):
    parent, left, right = input().split()
    binary_tree.add_node(parent, left, right)

root = 'A'
print(binary_tree.preorder(root))
print(binary_tree.inorder(root))
print(binary_tree.postorder(root))