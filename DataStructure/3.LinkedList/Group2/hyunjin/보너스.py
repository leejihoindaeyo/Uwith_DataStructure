class Node:
    def __init__(self, data, link=None):
        self.data = data
        self.link = link

class LinkedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head is None

    def getNode(self, pos):
        if pos < 0:
            return None
        node = self.head
        while pos > 0 and node is not None:
            node = node.link
            pos -= 1
        return node

    def insert_sorted(self, elem):
        new_node = Node(elem)
        if self.head is None or self.head.data.expo < new_node.data.expo:
            new_node.link = self.head
            self.head = new_node
            return

        current = self.head
        while current.link is not None and current.link.data.expo >= new_node.data.expo:
            current = current.link

        if current.data.expo == new_node.data.expo:
            current.data.coef += new_node.data.coef
            if current.data.coef == 0:
                self.delete(current)
            return

        new_node.link = current.link
        current.link = new_node

    def delete(self, pos):
        before = self.getNode(pos - 1)
        if before is None:
            if self.head is not None:
                self.head = self.head.link
        elif before.link is not None:
            before.link = before.link.link

class Term:
    def __init__(self, coef, expo):
        self.coef = coef
        self.expo = expo

    def __str__(self):
        return f"{self.coef:.1f} x^{self.expo}"

class SparsePoly(LinkedList):
    def read(self):
        while True:
            user_input = input("계수 차수 입력(종료:-1): ")
            if user_input == "-1 -1":
                break
            coef, expo = map(int, user_input.split())
            self.insert_sorted(Term(float(coef), expo))

    def display(self):
        if self.isEmpty():
            print("0", end="")
            return
        node = self.head
        first_term = True
        while node is not None:
            if not first_term:
                print(" + ", end="")
            else:
                first_term = False
            print(f"{node.data.coef:.1f} x^{node.data.expo}", end="")
            node = node.link

    def add(self, polyb):
        result = SparsePoly()
        node1 = self.head
        node2 = polyb.head

        while node1 is not None or node2 is not None:
            if node1 is None:
                result.insert_sorted(Term(node2.data.coef, node2.data.expo))
                node2 = node2.link
            elif node2 is None:
                result.insert_sorted(Term(node1.data.coef, node1.data.expo))
                node1 = node1.link
            elif node1.data.expo == node2.data.expo:
                new_coef = node1.data.coef + node2.data.coef
                if new_coef != 0:
                    result.insert_sorted(Term(new_coef, node1.data.expo))
                node1 = node1.link
                node2 = node2.link
            elif node1.data.expo > node2.data.expo:
                result.insert_sorted(Term(node1.data.coef, node1.data.expo))
                node1 = node1.link
            else:
                result.insert_sorted(Term(node2.data.coef, node2.data.expo))
                node2 = node2.link

        return result

if __name__ == "__main__":
    poly1 = SparsePoly()
    poly1.read()

    print("입력 다항식: ", end="")
    poly1.display()
    print()

    poly2 = SparsePoly()
    poly2.read()

    print("입력 다항식: ", end="")
    poly2.display()
    print()

    print("A = ", end="")
    poly1.display()
    print()

    print("B = ", end="")
    poly2.display()
    print()

    result = poly1.add(poly2)
    print("A + B = ", end="")
    result.display()
    print()