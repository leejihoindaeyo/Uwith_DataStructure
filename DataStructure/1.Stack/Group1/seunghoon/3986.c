#include <stdio.h>

#define MAX_LEN 100001

// '좋은 단어'인지 확인하는 함수
int good_word(char *word) {
    char stack[MAX_LEN];  // 스택으로 사용할 배열 설정
    int top = -1;         // 스택의 top 인덱스

    // 문자열을 한 글자씩 처리
    for (int i = 0; word[i] != '\0'; i++) {
        // 스택이 비어있지 않고, 스택의 가장 위의 문자와 현재 문자가 같으면 짝을 지음
        if (top != -1 && stack[top] == word[i]) {
            top--;  // 짝을 지은 문자는 스택에서 제거
        } else {
            stack[++top] = word[i];  // 현재 문자를 스택에 push
        }
    }

    // 스택이 비어 있으면 모든 문자가 짝을 이루어서 좋은 단어임
    return top == -1;
}

int main() {
    int n, total = 0;
    char word[MAX_LEN];

    // 단어의 수 입력
    scanf("%d", &n);

    // 단어를 하나씩 입력받고, '좋은 단어'인지 검사
    for (int i = 0; i < n; i++) {
        scanf("%s", word);  // 단어 입력
        if (good_word(word)) {
            total++;  // '좋은 단어'이면 카운트 증가
        }
    }

    // '좋은 단어'의 개수를 출력
    printf("%d\n", total);

    return 0;
}
