import sys
#시간 복잡도 주의하기 O(N)이 O(1)보다 복잡함
stack_l = list(input())#입력받은 문자열을 왼쪽 스택에 넣고 오른쪽 스택은 커서 이동용으로 만들어서 pop와 append를 통해 연결 리스트 형식으로 만듦
stack_r = []
n = int(input())
#왼쪽과 오른쪽 스택 사이에 커서 존재 왼쪽과 오른쪽 스택 방향 반대,  (왼쪽 스택)⊂ | ⊃(오른쪽 스택) 가운데 파이프 문자가 커서
for i in range(n):
    command = sys.stdin.readline().split()

    if command[0] == "L" and stack_l:
        stack_r.append(stack_l.pop())
    elif command[0] == "D" and stack_r:
        stack_l.append(stack_r.pop())
    elif command[0] == "B" and stack_l:
        stack_l.pop()
    elif command[0] == "P":
        stack_l.append(command[1])

print("".join(stack_l + list(reversed(stack_r))))

#https://corin-e.tistory.com/entry/%EB%B0%B1%EC%A4%80-1406-%EC%97%90%EB%94%94%ED%84%B0-%ED%8C%8C%EC%9D%B4%EC%8D%AC 그림 참고