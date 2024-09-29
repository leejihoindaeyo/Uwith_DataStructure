#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    queue<int>q;
    for(int i=0; i < n; i++)
    {   
        
        string s;
        int input;

        cin >> s;
        if(s == "push") 
        {   
            cin >> input;
            q.push(input);
        }
        else if(s == "pop") 
        {   
            if(q.empty()) cout << -1 << "\n";
            else 
            {   
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (s == "size") cout << q.size() << "\n";
        else if (s == "empty")
    {
        if (q.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
        else if (s == "front")
        {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(s == "back")
        {   
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
   
    
    return 0;
}