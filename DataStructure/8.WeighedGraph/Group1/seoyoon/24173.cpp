#include <iostream>
#include <vector>

using namespace std;

// 힙 재구성 함수
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;     // 루트를 최대값으로 설정
    int left = 2 * i + 1; // 왼쪽 자식
    int right = 2 * i + 2; // 오른쪽 자식

    // 왼쪽 자식이 루트보다 크다면
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 현재 최대값보다 크다면
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 최대값이 루트가 아니라면 교환
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // 재귀적으로 힙 재구성
    }
}

// 힙 정렬
void heapSort(vector<int>& arr, int n) {
    // 힙 구성
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 힙 정렬 과정
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);    // 루트 노드와 마지막 노드 교환
        heapify(arr, i, 0);      // 남은 요소로 힙 재구성
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
