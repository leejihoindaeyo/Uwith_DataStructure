#include <stdio.h>
#include <string.h>

#define MAX 10000  //명령의 최대 개수

int stack[MAX];
int top = -1;  //스택의 최상단을 가리킴 (비어있으면 -1이므로 )

//push 연산
void push(int x) {
    stack[++top] = x;
}

//pop 연산
int pop() {
    if (top == -1)
        return -1;  //스택이 비어있으면 -1 반환
    else
        return stack[top--];  //최상단 값을 반환하고 top 감소
}

//size 연산
int size() {
    return top + 1;  //스택에 들어있는 정수 개수
}

//empty 연산
int empty() {
    return (top == -1) ? 1 : 0;  //스택이 비어있으면 1, 아니면 0 반환
}

//top 연산
int get_top() {
    if (top == -1)
        return -1;  //스택이 비어있으면 -1 반환
    else
        return stack[top];  //스택의 최상단값을 반환
}
//시작이 되는 메인 함수
int main() {
    int n;  //명령의 개수 n으로 정의
    scanf("%d", &n); //정수 n을 입력받음

    for (int i = 0; i < n; i++) { //명령어 개수만큼 반복하고 명령어가 실행될 때마다 i를 1씩 증가시켜 n보다 클때 종료
        char command[10];  //명령어 저장
        scanf("%s", command);

        if (strcmp(command, "push") == 0) { //strcmp는 문자 비교 함수로 입력받은 명령어를 구분하는 줄
            int x;
            scanf("%d", &x);
            push(x); //스택에 push를 통해 입력받은 정수 x를 추가
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop()); //pop은 마지막으로 입력된 정수를 빼내고 출력하므로 printf 사용하여 출력
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size()); //스택에 있는 정수 개수를 출력
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty()); //스택이 비어있으면 1, 비어있지 않으면 0을 출력
        } else if (strcmp(command, "top") == 0) {
            printf("%d\n", get_top()); //스택의 최상단이 top이며 정수 x를 push로 입력받을 때나 pop을 통해 꺼낼때 바뀌고 get_top은 마지막으로 저장된 변수 top의 정수를 출력함
        }
    }

    return 0;
}
