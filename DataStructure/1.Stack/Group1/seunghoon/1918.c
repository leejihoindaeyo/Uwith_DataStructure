#include <stdio.h>
#include <string.h>

#define MAX 100 // 수식의 최대 길이 설정

int precedence(char op) { //연산자의 우선순위를 return 함수를 통해 반환함
    if (op == '*' || op == '/') return 2; // 곱셈, 나눗셈 우선순위는 2
    if (op == '+' || op == '-') return 1; // 덧셈, 뺄셈 우선순위는 1
    return 0; // 그 외의 경우는 우선순위가 없음
}

// 스택 관련 함수들
int empty(int top) {
    return top == -1; // 스택이 비어 있는지 확인
}

void push(char stack[], int *top, char value) {
    stack[++(*top)] = value; // 스택에 값을 추가
}

char pop(char stack[], int *top) {
    return stack[(*top)--]; // 스택에서 값을 제거하고 반환
}

char peek(char stack[], int top) {
    return stack[top]; // 스택의 최상단 값을 확인
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
void infix_to_postfix(char infix[], char postfix[]) {
    char stack[MAX]; // 연산자를 저장할 스택
    int top = -1;    // 스택의 최상단 인덱스
    int j = 0;       // 후위 표기식의 인덱스
    
    for (int i = 0; i < strlen(infix); i++) {
        char token = infix[i];
        
        // 피연산자는 바로 후위 표기식에 추가
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token;
        }
        // 여는 괄호는 스택에 push
        else if (token == '(') {
            push(stack, &top, token);
        }
        // 닫는 괄호가 나오면 여는 괄호가 나올 때까지 pop
        else if (token == ')') {
            while (!empty(top) && peek(stack, top) != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top); // 여는 괄호 제거
        }
        // 연산자 처리
        else {
            while (!empty(top) && precedence(peek(stack, top)) >= precedence(token)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, token); // 현재 연산자를 스택에 push
        }
    }
    
    // 스택에 남은 모든 연산자를 후위 표기식에 추가
    while (!empty(top)) {
        postfix[j++] = pop(stack, &top);
    }
    
    postfix[j] = '\0'; // 후위 표기식 문자열 끝에 null 문자 추가
}

int main() {
    char infix[MAX], postfix[MAX];

    // 중위 표기식 입력 받기
    scanf("%s", infix);

    // 중위 표기식을 후위 표기식으로 변환
    infix_to_postfix(infix, postfix);

    // 후위 표기식 출력
    printf("%s\n", postfix);

    return 0;
}
