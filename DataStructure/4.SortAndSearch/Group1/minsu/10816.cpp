#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n;
    unordered_map<int, int> card_count; // 숫자 카드와 그 개수를 저장

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        card_count[x]++; // 숫자 카드의 개수를 증가
    }

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    for (int i = 0; i < m; i++) {
        cout << card_count[arr2[i]] << " "; // arr2[i]의 개수를 출력 (없는 경우 기본값 0)
    }
    cout << endl;

    return 0;
}