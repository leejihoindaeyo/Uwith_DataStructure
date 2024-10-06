#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string input;
    int N = 0;
    char c;
    char in;

    stack<char> s1;  
    stack<char> s2;  

    cin >> input;
    cin >> N;

    for (char c : input) {
        s1.push(c);
    }

    for (int i = 0; i < N; i++) {
        cin >> c;

        if (c == 'L') {
            if (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if (c == 'D') {
            if (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if (c == 'B') {
            if (!s1.empty()) {
                s1.pop();
            }
        }
        else if (c == 'P') {
            cin >> in;
            s1.push(in);
        }
    }

    while (!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()){
        cout << s2.top();
        s2.pop();
    }
    return 0;
}