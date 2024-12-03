#include <bits/stdc++.h>
using namespace std;
void print(int a, int b);
void heap_sort(int A[]);
void build_min_heap(int A[], int n);
void heapify(int A[], int k, int n);

int N, K; 
int cnt = 0;
void print(int a, int b) {
    printf("%d %d\n", min(a, b), max(a, b));
    exit(0);
}
void heap_sort(int A[]) {
    // A[1..n]을 정렬한다.
    build_min_heap(A, N);

    for (int i = N; i > 1; i--) {
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        
        if (++cnt == K) print(A[1], A[i]);

        heapify(A, 1, i - 1);
    }
}
void build_min_heap(int A[], int n) {
    for (int i = (n / 2); i > 0; i--)
        heapify(A, i, n);
}
void heapify(int A[], int h, int n) {
    int left = 2 * h;
    int right = 2 * h + 1;
    int smaller;

    if (right <= n) {
        if (A[left] < A[right]) smaller = left;
        else smaller = right;
    }
    else if (left <= n) smaller = left;
    else return;

    if (A[smaller] < A[h]) {
        int tmp = A[h];
        A[h] = A[smaller];
        A[smaller] = tmp;

        if (++cnt == K) print(A[h], A[smaller]);

        heapify(A, smaller, n);
    }
}
int main() 
{
    scanf("%d %d", &N, &K);

    int* A = new int[N + 1];

    A[0] = 1000000000;
    for (int i = 1; i < N + 1; i++)
        scanf("%d", &A[i]);

    heap_sort(A);

    printf("-1\n");

	return 0;
}