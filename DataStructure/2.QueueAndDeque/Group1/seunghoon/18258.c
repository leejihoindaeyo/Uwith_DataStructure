#include <stdio.h>
#include <string.h>
#define MAX 2000000

int queue[MAX];
int front_idx = 0;
int back_idx = 0;

void push(int x) {
    queue[back_idx++] = x;
}

int pop() {
    if (front_idx == back_idx) return -1;
    return queue[front_idx++];
}

int size() {
    return back_idx - front_idx;
}

int empty() {
    return front_idx == back_idx ? 1 : 0;
}

int front() {
    if (front_idx == back_idx) return -1;
    return queue[front_idx];
}

int back() {
    if (front_idx == back_idx) return -1;
    return queue[back_idx - 1];
}

int main() {
    int N;
    scanf("%d", &N);

    char command[6];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", command);
        
        if (strcmp(command, "push") == 0) {
            scanf("%d", &x);
            push(x);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(command, "front") == 0) {
            printf("%d\n", front());
        } else if (strcmp(command, "back") == 0) {
            printf("%d\n", back());
        }
    }
    
    return 0;
}
