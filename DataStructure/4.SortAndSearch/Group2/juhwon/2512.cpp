#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0; // ������ ��
	int money = 0; // ������ ����
	int max = 0; // �� ����

	int answer = 0; // ��

	cin >> N;

	vector<int> v;

	// �� ������ �����û �Է� �ޱ�
	for (int i{ 0 }; i < N; i++) {
		cin >> money;
		v.push_back(money);
	}

	cin >> max;

	sort(v.begin(), v.end());

	int start = 1;
	int end = v.back();


	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i{ 0 }; i < v.size(); i++) {
			if (v[i] <= mid) {
				sum += v[i];
			}
			else {
				sum += mid;
			}
		}

		// ������ �ʰ��ϴ� ���
		if (sum > max) {
			end = mid - 1;
		}

		// ������ �ʰ����� �ʴ� ���
		else {
			if (mid <= end) {
				answer = mid;
			}
			start = mid + 1;
		}
	}

	cout << answer;
}