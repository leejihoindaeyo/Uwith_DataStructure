#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
bool removed[50];

int countLeafNodes(int node) {
    if (removed[node]) return 0;

    bool isLeaf = true;
    int count = 0;

    for (int child : tree[node]) {
        if (!removed[child]) {
            isLeaf = false;
            count += countLeafNodes(child);
        }
    }

    return isLeaf ? 1 : count;
}

int main() {
    int n, root, target;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;

        if (parent == -1) {
            root = i;
        }
        else {
            tree[parent].push_back(i);
        }
    }

    cin >> target;
    removed[target] = true;

    if (target == root) {
        cout << 0 << endl;
    }
    else {
        cout << countLeafNodes(root) << endl;
    }

    return 0;
}
