#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int internalNodes = n - m;
    int currentNode = 0;

    for (int i = 1; i <= internalNodes; i++) {
        cout << currentNode << " " << i << '\n';
        currentNode = i;
    }

    for (int i = internalNodes + 1; i < n; i++) {
        cout << currentNode << " " << i << '\n';
    }

    return 0;
}
