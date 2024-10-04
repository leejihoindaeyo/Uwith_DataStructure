#include <stdio.h>

#define MAX 100  // 스택의 최대 크기 설정

char stack[MAX]; //스택을 저장할 배열임
int top = -1;  // 스택의 상단 인덱스

// 스택이 비어 있는지 확인
int empty() {
    return top == -1;
}

// 스택에 요소 추가
void push(char c) { //1번 문제와 다르게 push는 값을 반환하지 않으므로 void를 씀
    stack[++top] = c;
}

// 스택에서 요소 제거 및 반환
char pop() { //1번 문제는 숫자를 반환하였고 현재 문제는 문자를 반환하므로 char를
    return stack[top--];
}

// 괄호 문자열을 검사하는 함수
int check(const char *str) { //입력받은 문자열 변수 str을 상수로 변경
    // 스택 초기화
    top = -1;  // 스택 비우기

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(str[i]);  // 여는 괄호를 스택에 추가
        } else if (str[i] == ')') {
            if (empty()) {
                return 0;  // 스택이 비어 있으면 닫는 괄호에 대한 균형맞지 않아 0으로 반환
            }
            pop();  // 여는 괄호와 매칭되는 닫는 괄호 제거
        }
    }

    // 반복문 종료 후 스택이 비어 있으면 유효한 VPS
    return empty() ? 1 : 0;  // 1: YES, 0: NO
}

int main() {
    int T;
    scanf("%d", &T);  // 테스트 케이스 수 입력

    for (int i = 0; i < T; i++) {
        char str[51];
        scanf("%s", str);  // 괄호 문자열 입력

        if (check(str)) {
            printf("YES\n");  // VPS인 경우
        } else {
            printf("NO\n");   // VPS가 아닌 경우
        }
    }

    return 0;
}
