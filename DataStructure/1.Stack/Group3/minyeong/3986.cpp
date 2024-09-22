// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// int main(void)
// {
//     int n;
//     stack<char>st;
//     cin >> n;
//     int cnt=0;
//     for (int i=0; i < n; i++)
//     {   
//         stack<char>st;
//         string s;
//         cin >> s;
//         for (int j=0; j < s.size(); j++)
//         {
//             if(st.empty())
//             {
//                 st.push(s[j]);
//             }
//             else 
//             {
//                 if (st.top() == s[j])
//                 {
//                     st.pop();
//                 }
//                 else if (st.top() != s[j] )
//                 {
//                     st.push(s[j]);
//                 }
//             }        
//         }
//         if (st.empty())
//         {
//             cnt++;
//         }
//     }
        
        
//     cout << cnt;

//     return 0;
// }