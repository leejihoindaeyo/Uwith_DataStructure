#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> vc1;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        vc1.push_back(a);
    }
    int m; cin >> m;
    vector<int> vc2;
    for (int i = 0; i < m; i++)
    {
        int a; cin >> a;
        vc2.push_back(a);
    }
    sort(vc1.begin(), vc1.end(), greater<int>());
    sort(vc2.begin(), vc2.end(), greater<int>());
    if (vc1[0] < vc2[0]) {
        cout << "-1\n";
        return 0;
    }
    int count = 0;
    while (!vc2.empty())
    {
        count += 1;
        for (int i = 0; i < vc1.size(); i++)
        {
            for (int j = 0; j < vc2.size(); j++)
            {
                if (vc1[i] >= vc2[j])
                {
                    vc2.erase(vc2.begin() + j);
                    break;
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
}