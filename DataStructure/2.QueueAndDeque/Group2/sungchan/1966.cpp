#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t_case = 0; cin >> t_case;
    while(t_case--){
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int num = 0, pos = 0, count = 0; cin >> num >> pos;
        for(int i = 0; i < num; i++){
            int impo; cin >> impo;
            q.push({i, impo}); pq.push(impo);
        }
        while(!q.empty()){
            int index = q.front().X;
            int value = q.front().Y; 
            q.pop();
            if(value == pq.top()){
                pq.pop(); ++count;
                if(index == pos){
                    cout << count << '\n';  
                    break;
                }
            }
            else q.push({index, value});
        }
    }
    return 0;
}