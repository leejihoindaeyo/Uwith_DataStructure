// 1966 프린터 큐

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

    for (int i = 0; i < T; i++) {
        cin >> N >> index;

        priority_queue<pair<int, int>> que; // 우선순위 큐
        queue<pair<int, int>> originalQueue;  // 초기값

        for (int j = 0; j < N; j++) {
            cin >> input;
            que.push({input, j});  // 우선순위 큐에 입력 값과 인덱스를 넣음
            originalQueue.push({input, j});  // 원래 순서대로 저장
        }

        int printOrder = 0;  

        
        while (!originalQueue.empty()) {

            pair<int, int> current = originalQueue.front();
            originalQueue.pop();

            if (current.first == que.top().first) {
                que.pop();
                printOrder++;

                if (current.second == index) {
                    cout << printOrder << endl;
                    break;
                }
            } else {
                    originalQueue.push(current);
            }
        }
    }

    return 0;
}
