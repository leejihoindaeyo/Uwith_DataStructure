#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 차량 개수
    cin >> N;

    vector<string> entryOrder(N); // 들어온 순서 저장
    unordered_map<string, int> position; // 들어온 차량 번호와 그 위치 저장

    // 차량 들어온 순서 입력
    for (int i = 0; i < N; i++) {
        cin >> entryOrder[i];
        position[entryOrder[i]] = i; // 차량 번호와 그 인덱스 저장
    }

    vector<string> exitOrder(N); // 나간 순서 저장
    for (int i = 0; i < N; i++) {
        cin >> exitOrder[i];
    }

    // 순서 위반 계산
    int violations = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 현재 나간 차량의 들어온 순서가 더 나중인데 먼저 나갔다면 위반
            if (position[exitOrder[i]] > position[exitOrder[j]]) {
                violations++;
                break; // 한 번 위반이 확인되면 더 이상 비교하지 않음
            }
        }
    }

    cout << violations << endl; // 위반된 차량 순서 출력
    return 0;
}