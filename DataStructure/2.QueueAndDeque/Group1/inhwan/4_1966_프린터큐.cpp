#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cde1966() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int n, m;
        cin >> n >> m;  // n: 문서의 수, m: 궁금한 문서의 인덱스

        queue<pair<int, int>> list1; // (문서, 중요도)
        vector<int> import(n);  // 중요도

        // 문서의 중요도 입력
        for (int j = 0; j < n; j++) {
            cin >> import[j];
            list1.push({ j, import[j] }); // (문서 인덱스, 중요도)를 큐에 저장
        }

        // 중요도 정렬 
        sort(import.begin(), import.end(), greater<int>());

        int count = 0;
        int idx = 0;

        while (!list1.empty()) {
            int currentIdx = list1.front().first;
            int currentPriority = list1.front().second;
            list1.pop();

            // 현재 문서가 가장 높은 중요도 출력
            if (currentPriority == import[idx]) {
                count++;
                idx++;  // 다음으로 높은 중요도

                // 궁금한 문서(m)가 출력되는 순서를 출력
                if (currentIdx == m) {
                    cout << count << '\n';
                    break;
                }
            }
            else {
                list1.push({ currentIdx, currentPriority }); // 중요도가 높지 않으면 뒤로 보냄
            }
        }
    }

    return 0;
}
