#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cranes[100];
    int boxes[100];

    // ũ������ ����
    for (int i = 0; i < n; i++) {
        cin >> cranes[i];
    }

    // �ڽ� ����
    for (int i = 0; i < m; i++) {
        cin >> boxes[i];
    }

    // ũ���ΰ� �ڽ��� ������������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cranes[i] < cranes[j]) {
                int temp = cranes[i];
                cranes[i] = cranes[j];
                cranes[j] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (boxes[i] < boxes[j]) {
                int temp = boxes[i];
                boxes[i] = boxes[j];
                boxes[j] = temp;
            }
        }
    }

    int time = 0;
    int boxIndex = 0;

    // �ڽ��� �� �ű� ������ �ݺ�
    while (boxIndex < m) {
        time++;
        // ũ������ �� ���� �� �ڽ�
        for (int i = 0; i < n; i++) {
            if (boxIndex < m && cranes[i] >= boxes[boxIndex]) {
                boxIndex++;
            }
        }
    }

    cout << time << endl;
    return 0;
}
