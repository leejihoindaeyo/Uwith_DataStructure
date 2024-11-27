class Node:
    def __init__(self, data, link=None):
        self.data = data #node가 저장 할 값
        self.link = link #다음 node 에 대한 참조(링크)를 저장, 링크가 none 이면 이 노드가 list 의 마지막 node 라는 뜻

class LinkedList:
    def __init__(self):
        self.head = None #list 의 첫 번째 노드, 리스트 가 비어 있으면 none
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

# Term 클래스 는 각 항을 나타냄
class Term:
    def __init__(self, coef, expo):
        self.coef = coef  # 계수
        self.expo = expo  # 지수

    def __str__(self):
        return f"{self.coef}x^{self.expo}" if self.expo != 0 else f"{self.coef}"

# SparsePoly 클래스 는 희소 다항식 을 나타냄
class SparsePoly(LinkedList): # LinkedList 상속
    # 다항식 을 입력 받아 리스트 에 추가
    def read(self, terms):
        for coef, expo in terms:
            self.insert(0, Term(coef, expo))  # (계수, 지수) 형태로 입력 받아 추가

    # 다항식 을 출력
    def display(self):
        if self.isEmpty():
            print("0")
        else:
            result = []
            node = self.head
            while node is not None:
                result.append(str(node.data))
                node = node.link
            print(" + ".join(result))

    # 두 다항식 의 덧셈
    def add(self, poly):
        result = SparsePoly()
        p1 = self.head
        p2 = poly.head

        while p1 is not None and p2 is not None:
            term1 = p1.data
            term2 = p2.data

            if term1.expo > term2.expo:
                result.insert(0, Term(term1.coef, term1.expo))
                p1 = p1.link
            elif term1.expo < term2.expo:
                result.insert(0, Term(term2.coef, term2.expo))
                p2 = p2.link
            else:
                coef_sum = term1.coef + term2.coef
                if coef_sum != 0:
                    result.insert(0, Term(coef_sum, term1.expo))
                p1 = p1.link
                p2 = p2.link

        # 남은 항을 추가
        while p1 is not None:
            result.insert(0, Term(p1.data.coef, p1.data.expo))
            p1 = p1.link

        while p2 is not None:
            result.insert(0, Term(p2.data.coef, p2.data.expo))
            p2 = p2.link

        return result
