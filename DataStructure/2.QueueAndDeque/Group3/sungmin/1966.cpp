#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int T, N;
    int input;
    int index;
    
    cin >> T;

    // 테스트 케이스마다 반복
    for (int i = 0; i < T; i++) {
        cin >> N >> index;

        // 큐 선언 (우선순위 큐는 최대 힙을 사용)
        priority_queue<pair<int, int>> que;
        queue<pair<int, int>> originalQueue;  // 원래 순서를 유지하기 위한 큐

        // N개의 입력을 받으면서 우선순위 큐와 원본 큐에 삽입
        for (int j = 0; j < N; j++) {
            cin >> input;
            que.push({input, j});  // 우선순위 큐에 입력 값과 인덱스를 넣음
            originalQueue.push({input, j});  // 원래 순서대로 저장
        }

        int printOrder = 0;  // 출력 순서를 추적하는 변수

        // 출력 순서를 알아내기 위한 반복
        while (!originalQueue.empty()) {
            // 원래 큐에서 맨 앞 원소 확인
            pair<int, int> current = originalQueue.front();
            originalQueue.pop();

            // 현재 원소가 우선순위 큐의 가장 우선순위가 높은 원소와 일치하는지 확인
            if (current.first == que.top().first) {
                // 가장 큰 우선순위 원소를 찾았으므로 pop()하고 순서 증가
                que.pop();
                printOrder++;

                // 우리가 찾는 인덱스가 맞다면, 출력 순서 출력
                if (current.second == index) {
                    cout << printOrder << endl;
                    break;
                }
            } else {
                // 우선순위가 맞지 않으면 다시 큐의 뒤로 이동
                originalQueue.push(current);
            }
        }
    }

    return 0;
}
