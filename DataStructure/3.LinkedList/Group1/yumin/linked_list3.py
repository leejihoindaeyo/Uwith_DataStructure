class Node:
    def __init__(self, data, link=None):
        self.data = data
        self.link = link

class LinkedList:
    def __init__(self):
        self.head = None #첫 노드

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

    def getEntry(self, pos): #노드에 있는 data 반환
        node = self.getNode(pos)
        if node is None:
            return None
        else:
            return node.data

    def insert(self, pos, elem):
        before = self.getNode(pos - 1) #이전 노드
        if before is None: #이전 노드가 없으면
            self.head = Node(elem, self.head) #첫 노드 data에 elem 삽입
        else: #이전 노드가 있으면
            node = Node(elem, before.link)
            before.link = node #이전 노드 링크에 새 노드 연결

    def delete(self, pos):
        before = self.getNode(pos - 1)
        if before is None: #이전 노드가 없으면 (삭제하려는 노드가 첫 노드라면)
            if self.head is not None: #리스트가 비어있지 않다면
                self.head = self.head.link #삭제하려는 첫 노드를 그 다음 노드로 연결해 삭제
        elif before.link is not None: #이전 노드가 있으면
            before.link = before.link.link #이전 노드를 삭제할 노드의 다음 노드로 연결해 삭제

class Term:
    def __init__(self, expo, coef):
        self.expo = expo  # 지수
        self.coef = coef  # 계수

class SparsePoly(LinkedList):
    def read(self):
        numofterms = int(input("항의 개수 입력: "))
        for i in range(numofterms):
            expo = float(input("지수 입력: "))
            coef = float(input("계수 입력: "))
            self.insert_term(expo, coef)  # 인자 순서 맞춤

    def insert_term(self, expo, coef):
        if self.isEmpty():  # 비어 있으면 바로 삽입
            self.head = Node(Term(expo, coef), None)
        else:
            current = self.head  # 현재 노드를 첫 노드로
            prev = None  # 삽입할 노드의 이전 위치 노드는 비워둠
            while current is not None and current.data.expo > expo:
                prev = current
                current = current.link

            if current is not None and current.data.expo == expo:  # 같은 지수일 때 계수 합치기
                current.data.coef += coef
                if current.data.coef == 0:  # 계수가 0이면 삭제
                    if prev is None:
                        self.head = current.link
                    else:
                        prev.link = current.link
            else:
                new_node = Node(Term(expo, coef), current)
                if prev is None:
                    self.head = new_node
                else:
                    prev.link = new_node

    def display(self):
        if self.isEmpty():
            print("0")
            return

        current = self.head
        result = []
        while current is not None:
            term = current.data
            if term.coef != 0:
                result.append(f"{term.coef}x^{term.expo}")
            current = current.link

        print(" + ".join(result))

    def add(self, poly):
        result = SparsePoly()
        p1 = self.head
        p2 = poly.head

        while p1 is not None and p2 is not None:
            if p1.data.expo == p2.data.expo:
                coef_sum = p1.data.coef + p2.data.coef
                if coef_sum != 0:
                    result.insert_term(p1.data.expo, coef_sum)
                p1 = p1.link
                p2 = p2.link
            elif p1.data.expo > p2.data.expo:
                result.insert_term(p1.data.expo, p1.data.coef)
                p1 = p1.link
            else:
                result.insert_term(p2.data.expo, p2.data.coef)
                p2 = p2.link

        while p1 is not None:
            result.insert_term(p1.data.expo, p1.data.coef)
            p1 = p1.link

        while p2 is not None:
            result.insert_term(p2.data.expo, p2.data.coef)
            p2 = p2.link

        return result
