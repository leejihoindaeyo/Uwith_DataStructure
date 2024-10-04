#define _CRT_SECURE_NO_WARNINGS //보안 경고 무시설정**
#include <stdio.h>
#include <string.h> //문자열 관련 함수 라이브러리

char S[100001];
char stack[100001]; //단어를 임시로 저장하기 위한 스택
char answer[100001]; //최종결과 문자열 저장할 배열

int main() {
    int i, top = -1, index = 0; //index는 결과 문자열 answer의 현재 인덱스를 알게함
    scanf("%[^\n]", S);  //한 줄 입력 받기**
    int len = strlen(S); //문자열 S의 길이를 계산하여 len에 저장

    for (i = 0; i < len; i++) { //문자열의 모든 문자에 대해 반복
        if (S[i] == '<') { //현재 문자가 태그의 시작인 <인지 확인함
            while (top != -1) { //스택이 비어있지 않는 동안만 반복
                answer[index++] = stack[top--];  //스택의 맨 위 문자를 빼내어 answer에 추가함
            }
            while (S[i] != '>') { //현재 문자가 태그의 끝인 >가 아닐때까지 반복
                answer[index++] = S[i++];  // 태그의 문자를 그대로 answer에 추가
            }
            answer[index++] = S[i];  // '>' 추가
        } else if (S[i] == ' ') { //공백일때
            while (top != -1) {
                answer[index++] = stack[top--];  //스택의 맨 위 문자를 빼내어 answer에 추가함
            }
            answer[index++] = ' ';  // 공백 추가
        } else {
            // 단어를 스택에 저장
            stack[++top] = S[i];
        }
    }

    // 남아있는 단어 처리
    while (top != -1) {
        answer[index++] = stack[top--];
    }

    answer[index] = '\0';  // 문자열 종료
    printf("%s\n", answer);  // 결과 출력
    return 0;
}
