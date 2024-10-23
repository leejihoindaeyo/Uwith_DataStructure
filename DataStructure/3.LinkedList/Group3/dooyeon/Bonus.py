class Node:
    def __init__(self, data, link=None):
        self.data = data
        self.link = link

class LinkedList:
    def __init__(self):
        self.head = None
    def isEmpty(self):
        return self.head is None
    def isFull(self):
        return False
    def getNode(self, pos):
        if pos < 0:
            return None
        node = self.head
        while pos > 0 and node is not None:
            node = node.link
            pos -= 1
        return node
    def getEntry(self, pos):
        node = self.getNode(pos)
        if node is None:
            return None
        else:
            return node.data
    def insert(self, pos, elem):
        before = self.getNode(pos - 1)
        if before is None:
            self.head = Node(elem, self.head)
        else:
            node = Node(elem, before.link)
            before.link = node
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
        return f"{self.coef}x^{self.expo}" if self.expo != 0 else f"{self.coef}"
        
class SparsePoly(LinkedList):
    def read(self, terms):
        for coefficient, exponent in terms:
            self.insert(0, Term(coefficient, exponent))
    def display(self):
        if self.isEmpty():
            print("0")
        else:
            result_terms = []
            current_node = self.head
            while current_node is not None:
                result_terms.append(str(current_node.data))
                current_node = current_node.link
            print(" + ".join(result_terms))
    def add(self, other_poly):
        result_poly = SparsePoly()
        current_node_self = self.head
        current_node_other = other_poly.head
        while current_node_self is not None and current_node_other is not None:
            term_self = current_node_self.data
            term_other = current_node_other.data
            if term_self.exponent > term_other.exponent:
                result_poly.insert(0, Term(term_self.coef, term_self.exponent))
                current_node_self = current_node_self.link
            elif term_self.exponent < term_other.exponent:
                result_poly.insert(0, Term(term_other.coef, term_other.exponent))
                current_node_other = current_node_other.link
            else:
                coef_sum = term_self.coef + term_other.coef
                if coef_sum != 0:
                    result_poly.insert(0, Term(coef_sum, term_self.exponent))
                current_node_self = current_node_self.link
                current_node_other = current_node_other.link
        while current_node_self is not None:
            result_poly.insert(0, Term(current_node_self.data.coef, current_node_self.data.exponent))
            current_node_self = current_node_self.link
        while current_node_other is not None:
            result_poly.insert(0, Term(current_node_other.data.coef, current_node_other.data.exponent))
            current_node_other = current_node_other.link
        return result_poly