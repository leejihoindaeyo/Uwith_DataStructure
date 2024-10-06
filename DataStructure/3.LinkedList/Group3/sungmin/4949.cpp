#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str1;

    while (1) {
        getline(cin, str1);  

        if (str1 == ".") {
            break;
        }

        stack<char> st;  

        bool isValid = true;  

        for (char ch : str1) {
            if (ch == '(' || ch == '[') {
                st.push(ch);  
            } 
            else if (ch == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();  
                } else {
                    isValid = false;  
                    break;
                }
            } 
            else if (ch == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();  
                } else {
                    isValid = false;  
                    break;
                }
            }
        }

        if (isValid && st.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
