#include <bits/stdc++.h>
using namespace std;
list<char> L; 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char command, p_command;
    string a; cin >> a;
    int count; cin >> count;
    for(auto c : a)
        L.push_back(c);
    auto t = L.end();
    for(int i = 0; i < count; i++){
        cin >> command;

        if(command == 'L'){
            if(t != L.begin())
                t--;
        }
        else if(command == 'D'){
            if(t != L.end())
                t++;
        }
        else if(command == 'B'){
            if(t != L.begin())
                t = L.erase(--t); // t가 가리키는 값을 제거하고, 그 다음 원소의 위치 반환.
        }
        else if(command == 'P'){
            cin >> p_command;
            L.insert(t, p_command);
        }
    }
    for(auto it : L)  // == for(auto it = L.begin(); it != L.end(); it++) cout << *it;
        cout << it;
    cout << '\n';
} 