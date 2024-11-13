#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> enterOrder;
    string exitOrder[1000];

    // 터널에 들어간 순서
    for (int i = 0; i < n; ++i) {
        string car;
        cin >> car;
        enterOrder[car] = i;
    }

    // 터널에서 나오는 순서
    for (int i = 0; i < n; ++i) {
        cin >> exitOrder[i];
    }

    int overtakes = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (enterOrder[exitOrder[i]] > enterOrder[exitOrder[j]]) {
                overtakes++;
                break;
            }
        }
    }

    cout << overtakes << endl;
    return 0;
}
