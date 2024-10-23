class Node:
    def __init__(self, data, link=None):
        self.data = data # 데이터
        self.link = link # 포인터 

class LinkedList:
    def __init__(self):
        self.head = None # 연결리스트의 첫 번째 노드 
    
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
    def __init__(self, expo, coef):
        self.expo = expo  # 지수 (exponent)
        self.coef = coef  # 계수 (coefficient)
        
    def __str__(self):
        return f"{self.coef:.1f}x^{self.expo}"

class SparsePoly(LinkedList):
    
    def read(self):
        print("다항식을 입력하세요. 종료하려면 계수와 차수에 -1을 입력하세요.")
        while True:
            coef, expo = map(int, input("계수 차수 입력 (종료: -1 -1): ").split())
            
            if coef == -1 and expo == -1:
                break
            
            term = Term(expo, coef)
            # 차수 순서대로 삽입하기 위해 적절한 위치를 찾습니다.
            current = self.head
            pos = 0
            while current is not None and current.data.expo > expo:
                current = current.link
                pos += 1
            
            self.insert(pos, term)
    
    def display(self):
        if self.isEmpty():  
            print("다항식이 비어 있습니다.")
        else:
            current = self.head
            while current is not None:
                print(current.data, end=" ")
                current = current.link
            print()
    
    def __add__(self, other):
        result = SparsePoly()
        
        p1 = self.head
        p2 = other.head
        
        while p1 is not None and p2 is not None:
            term1 = p1.data
            term2 = p2.data
            
            if term1.expo == term2.expo:
                # 계수를 합치고 0이 아닌 경우에만 추가
                new_coef = term1.coef + term2.coef
                if new_coef != 0:
                    result.insert(0, Term(term1.expo, new_coef))
                p1 = p1.link
                p2 = p2.link
            elif term1.expo > term2.expo:
                result.insert(0, Term(term1.expo, term1.coef))
                p1 = p1.link
            else:
                result.insert(0, Term(term2.expo, term2.coef))
                p2 = p2.link
        
        # 남아 있는 항들을 결과에 추가
        while p1 is not None:
            term1 = p1.data
            result.insert(0, Term(term1.expo, term1.coef))
            p1 = p1.link
        
        while p2 is not None:
            term2 = p2.data
            result.insert(0, Term(term2.expo, term2.coef))
            p2 = p2.link
        
        # 다항식을 뒤집어서 차수가 큰 순서대로 정렬
        final_result = SparsePoly()
        current = result.head
        while current is not None:
            final_result.insert(0, current.data)
            current = current.link
            
        return final_result


poly1 = SparsePoly()
poly2 = SparsePoly()

poly1.read()
poly1.display()

poly2.read()
poly2.display()

result = poly1 + poly2
result.display()


