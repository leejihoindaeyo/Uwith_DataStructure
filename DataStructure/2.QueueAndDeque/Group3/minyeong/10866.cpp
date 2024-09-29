#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<int>d;
    for(int i=0; i < n; i++)
    {   
        
        string s;
        int input;

        cin >> s;
        if(s == "push_front") 
        {     
            cin >> input;
            d.push_front(input);
        }
        else if(s == "push_back") 
        {     
            cin >> input;
            d.push_back(input);
        }
        else if(s == "pop_front") 
        {   
            if(d.empty()) cout << -1 << "\n";
            else 
            {   
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
         else if(s == "pop_back") 
        {   
            if(d.empty()) cout << -1 << "\n";
            else 
            {   
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if (s == "size") cout << d.size() << "\n";
        else if (s == "empty")
    {
        if (d.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
        else if (s == "front")
        {
            if(d.empty()) cout << -1 << "\n";
            else cout << d.front() << "\n";
        }
        else if(s == "back")
        {   
            if(d.empty()) cout << -1 << "\n";
            else cout << d.back() << "\n";
        }
    }
   
    
    return 0;
}