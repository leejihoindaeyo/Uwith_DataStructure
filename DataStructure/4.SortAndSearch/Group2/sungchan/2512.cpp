#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> vc(n);
    for(int i = 0; i < n; i++)
        cin >> vc[i];
    int M; cin >> M;
    sort(vc.begin(), vc.end());
    int low = 0; int high = vc[n-1]; int result = 0;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int total = 0;

        for(int i = 0; i < n; i++)
        {
            if(vc[i] > mid) total += mid;
            else total += vc[i];
        }

        if(total <= M)
        {
            result = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << result;
    return 0;
}
