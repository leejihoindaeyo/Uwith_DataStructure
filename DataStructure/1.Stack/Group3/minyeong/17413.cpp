// #include <iostream>
// #include <string>
// #include<vector>
// #include <stack>
// using namespace std;

// int main(void)
// {
//     string s;
//     string result;
//     stack<char>st;
//     bool check = false;
//     getline(cin,s);
//     for (char c : s)
//     {
//         if (c == '<') 
//         {
//             while(!st.empty()) // < 앞에 나온 인덱스들 뒤집어서 결과에 추가
//             {
//                 result += st.top(); // 맨위의 인덱스 추가 즉 뒤집어서 추가됨
//                 st.pop(); // 그 후 맨 위 인덱스 삭제
//             }
//             result += c;
//             check = true; // < 안에 있다는 표시
//         }
//         else if(c == '>') 
//         {
//             result += c; 
//             check = false; // 다시 문 닫음
//         }
//         else if(check) // <>안에 있는 인덱스들은 그냥 추가
//         {
//             result += c;
//         }
//         else if (c == ' ')
//         {
//             while(!st.empty()) // 다시 뒤집어서 추가
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             result += ' ';
//         }
//         else // 그 외의 일반 경우는 일단 스택에 추가함
//         {
//             st.push(c);
//         }
//     }
//     while(!st.empty()) // 마지막에 스택이 빌 때까지 뒤집어서 추가 후 삭제
//     {
//         result += st.top();
//         st.pop();
//     }
   
//     cout << result << endl;

//     return 0;
// }
