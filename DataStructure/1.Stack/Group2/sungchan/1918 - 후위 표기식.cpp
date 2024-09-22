#include <bits/stdc++.h>
using namespace std;
int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}
int main(){
    string input, ans;
    stack<char> s;
    char c; cin >> input;
    for(int i = 0; i < input.length(); i++){
        c = input[i];
        
        if(c >= 'A' && c <= 'Z'){
            ans += c; continue;
        }

        if(s.empty() || c == '('){
            s.push(c); continue;
        }
        
        if(c == ')'){
            while(s.top() != '(')
            {
                ans += s.top(); s.pop();
            }
            s.pop();
            continue;
        }

        if(priority(s.top()) < priority(c)){
            s.push(c);
        }
        
        else{
            while(!s.empty() && priority(s.top()) >= priority(c)){
                ans += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout << ans << '\n';
    return 0;
}