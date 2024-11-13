#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int budgets[10000];
    for (int i = 0; i < n; ++i) {
        cin >> budgets[i];
    }

    int totalBudget;
    cin >> totalBudget;

    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        if (budgets[i] > right) {
            right = budgets[i];
        }
    }

    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (budgets[i] > mid) {
                sum += mid;
            }
            else {
                sum += budgets[i];
            }
        }

        if (sum <= totalBudget) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
