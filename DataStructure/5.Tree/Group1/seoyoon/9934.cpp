#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[10];

void constructTree(vector<int>& nodes, int depth) {
    if (nodes.empty()) return;
    int mid = nodes.size() / 2;
    tree[depth].push_back(nodes[mid]);
    vector<int> left(nodes.begin(), nodes.begin() + mid);
    vector<int> right(nodes.begin() + mid + 1, nodes.end());
    constructTree(left, depth + 1);
    constructTree(right, depth + 1);
}

int main() {
    int k;
    cin >> k;
    int numNodes = (1 << k) - 1;
    vector<int> nodes(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nodes[i];
    constructTree(nodes, 0);
    for (int i = 0; i < k; i++) {
        for (int node : tree[i]) cout << node << " ";
        cout << '\n';
    }
    return 0;
}
