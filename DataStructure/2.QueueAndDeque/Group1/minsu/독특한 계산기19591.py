import sys
from collections import deque
input = sys.stdin.readline

formula = list(input().rstrip())
nums = deque()
operators = deque()
first_operators = ["*", "/"] # 우선순위 첫 번째
second_operators = ["+", "-"] # 우선순위 두 번째
FRONT, BACK = "front", "back"

def calculator(a, b, operator):
    if operator == "+":
        return a + b
    if operator == "-":
        return a - b
    if operator == "*":
        return a * b
    if operator == "/":
        if a * b >= 0:
            return a // b
        else: return -(-a // b)

num_string = ""        
# nums, operators에 숫자와 연산자 나눠 담기
for x in formula:
    if not x.isnumeric() and num_string: # 숫자가 아니고(연산자이고) 맨 첫 번째가 부호가 아닌 경우 (이미 처리할 숫자가 존재함)
        operators.append(x)
        if num_string: # num_string에 쌓인 값이 있으면 숫자로 변환해서 넣어줌
            nums.append(int(num_string))
        num_string = "" # append 했으니까 비워주기
    else: # 숫자인 경우 혹은 첫 번째 숫자 앞에 부호 붙은 경우
        num_string += x # 0 들어오거나 숫자 두자리수 이상일 경우 커버
if num_string: nums.append(int(num_string)) # 마지막에 남은 애 처리해줌 (연산자가 올 경우에만 숫자를 append해줬기 때문)

while operators:    
    # 맨 뒤 연산자의 우선순위가 더 높을 때 뒤부터
    if operators[-1] in first_operators and operators[0] in second_operators:
        direction = BACK # 처리 방향 뒤부터
    # 맨 앞 연산자의 우선순위가 더 높을 때 앞부터
    if operators[0] in first_operators and operators[-1] in second_operators:
        direction = FRONT
    # 우선순위가 같으면 
    if (operators[0] in first_operators and operators[-1] in first_operators) or (operators[0] in second_operators and operators[-1] in second_operators):
        # 뒤에 거 계산 결과가 더 크면 뒤에 거부터 계산
        if calculator(nums[0], nums[1], operators[0]) < calculator(nums[-2], nums[-1], operators[-1]):        
            direction = BACK
        else: # 결과값이 같거나 앞이 더 크면 앞부터 계산
            direction = FRONT
    
    # 실제 계산 로직
    if direction == FRONT: # 앞부터 계산
        a = nums.popleft()
        b = nums.popleft()
        operator = operators.popleft()
        nums.appendleft(calculator(a, b, operator)) # 계산 결과 넣어주기  
    else: # 뒤부터 계산      
        b = nums.pop()
        a = nums.pop()
        operator = operators.pop()
        nums.append(calculator(a, b, operator)) 

print(*nums, sep='')

