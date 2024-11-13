#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cranes[100];
    int boxes[100];

    // 크레인의 무게
    for (int i = 0; i < n; i++) {
        cin >> cranes[i];
    }

    // 박스 무게
    for (int i = 0; i < m; i++) {
        cin >> boxes[i];
    }

    // 크레인과 박스를 내림차순으로
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

    // 박스를 다 옮길 때까지 반복
    while (boxIndex < m) {
        time++;
        // 크레인은 한 번에 한 박스
        for (int i = 0; i < n; i++) {
            if (boxIndex < m && cranes[i] >= boxes[boxIndex]) {
                boxIndex++;
            }
        }
    }

    cout << time << endl;
    return 0;
}
