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
class Term :
    def __init__(self,expo, coef):
        self.expo = expo# 지수 설정
        self.coef = coef# 계수 설정
    def __str__(self): # 객체를 문자와 같이 표현할때 (display에서 사용) 아래와 같은 값을 반환하게 함
        return f'{self.coef}x^{self.expo}' # 반환 형태를 지수와 계수를 포함하여 설정



class SparsePoly(LinkedList) :
    def read( self ):
        terms = int(input("입력할 항의 개수: "))
        for _ in range(terms):
           coef = int(input("계수: "))
           expo = int(input("지수: "))
           self.insert(0,Term(coef,expo)) # 입력받은 항을 리스트의 맨 앞에 삽입
    def display( self ):#다항식 출력
        if self.isEmpty():
           print("0") #리스트가 비어있으면 0을 출력
        else: #리스트의 각 노드들을 순차적으로 탐색하여 계수와 지수를 출력함.
            node = self.head
            while node is not None: 
                print(f'{node.data.coef}x^{node.data.expo}',end=' ')
                if node.link is not None: #현재의 노드 뒤에 다른 노드가 있으면 +기호 출력
                    print('+', end = ' ')
                node = node.link
            print()

    def add( self, poly ): # 두 개의 희소 다항식을 더함
        result = SparsePoly()
        p1 = self.head   #첫 번째와 두 번째 다항식의 헤드를 가리킴
        p2 = poly.head

        while p1 is not None and p2 is not None:

            if p1.data.expo > p2.data.expo:  # 두 다항식의 각 항을 비교하여 큰 지수부터 차례대로 결과에 추가함
                result.insert(0, Term(p1.data.coef, p1.data.expo))
                p1 = p1.link
            elif p1.data.expo < p2.data.expo:
                result.insert(0, Term(p2.data.coef, p2.data.expo))
                p2 = p2.link
            else:
                coef_sum = p1.data.coef + p2.data.coef   # 지수가 같은 항들은 계수끼리 더함
                if coef_sum != 0:
                    result.insert(0, Term(coef_sum, p1.data.expo))
                p1 = p1.link
                p2 = p2.link

        while p1 is not None:   # 첫 번째 다항식의 남은 항들을 모두 결과에 추가함
            result.insert(0, Term(p1.data.coef, p1.data.expo))
            p1 = p1.link

        while p2 is not None:   # 두 번째 다항식의 남은 항들을 모두 결과에 추가함
            result.insert(0, Term(p2.data.coef, p2.data.expo))
            p2 = p2.link

        return result # 덧셈 결과 반환
