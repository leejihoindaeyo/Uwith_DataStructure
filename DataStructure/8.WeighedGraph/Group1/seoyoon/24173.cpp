#include <iostream>
#include <vector>

using namespace std;

// �� �籸�� �Լ�
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;     // ��Ʈ�� �ִ밪���� ����
    int left = 2 * i + 1; // ���� �ڽ�
    int right = 2 * i + 2; // ������ �ڽ�

    // ���� �ڽ��� ��Ʈ���� ũ�ٸ�
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ �ڽ��� ���� �ִ밪���� ũ�ٸ�
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // �ִ밪�� ��Ʈ�� �ƴ϶�� ��ȯ
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // ��������� �� �籸��
    }
}

// �� ����
void heapSort(vector<int>& arr, int n) {
    // �� ����
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // �� ���� ����
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);    // ��Ʈ ���� ������ ��� ��ȯ
        heapify(arr, i, 0);      // ���� ��ҷ� �� �籸��
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
