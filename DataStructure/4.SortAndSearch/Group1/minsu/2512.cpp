#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0; // 지방의 수
	int money = 0; // 배정된 예산
	int M = 0; // 총 예산

	int answer = 0; // 답

	cin >> N;

	vector<int> v; // 각 지방의 예산 요청을 저장하는 벡터

	for (int i = 0; i < N; i++) {
		cin >> money;
		v.push_back(money);
	}

	cin >> M;

	sort(v.begin(), v.end()); // 오름차순 정렬
//초기 범위 = 1~제일 큰 수
	int start = 1;
	int end = v.back();


	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] <= mid) { // 상한선보다 작거나 같은 경우
				sum += v[i]; // 그냥 그 값을 더함
			}
			else {
				sum += mid; // 상한선보다 더 큰 경우에는 상한선을 더해준다.
			}
		}

		// 예산을 초과하는 경우
		if (sum > M) {
			end = mid - 1; // 상한선을 낮춰준다.
		}

		// 예산을 초과하지 않는 경우
		else {
			if (mid <= end) {
				answer = mid;
			}
			start = mid + 1; // 상한선을 높여줌
		}
	}

	cout << answer << endl;
    return 0;
}