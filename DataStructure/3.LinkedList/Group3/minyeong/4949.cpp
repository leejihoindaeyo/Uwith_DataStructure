#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{   
    string s;
    while(true)
    {
        stack<char>st;
        getline(cin,s);
        if(s == ".")
            break;
        bool TrueFalse = true;
        for(auto c : s)
        {
            if(c =='(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    TrueFalse = false;
                    break;
                }
                st.pop(); // 나머지 경우는 c가 (일때 이므로 pop으로 짝을 맞춰서 삭제
            }
            else if (c == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    TrueFalse = false;
                    break;
                }
                st.pop(); // 나머지 경우는 c가 [일때 이므로 pop으로 짝을 맞춰서 삭제
            }
        }
        if(!st.empty()) TrueFalse = false;
        if(TrueFalse) cout << "yes" << "\n";
        else cout << "no" << "\n"; 
    }
    return 0;
}