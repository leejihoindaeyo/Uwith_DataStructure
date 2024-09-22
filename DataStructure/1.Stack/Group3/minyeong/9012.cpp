// #include <iostream>
// #include <string>
// #include <stack>
// using namespace  std;

// int main(void)
// {
//     int n;
//     cin >> n;

//     for (int i=0; i < n; i++)
//     {
//         stack<char> vps;
//         string s;
//         cin >> s;
//         bool empty_check = true;

//         for (int j=0; j < s.size(); j++)
//         {   if(vps.empty() && s[j] == ')')
//             {
//                 empty_check = false;
//                 break;
//             }
//             else if (s[j] == '(')
//             {
//                 vps.push(s[j]);
//             }
//             else if (vps.size() != 0 && s[j] == ')')
//             {
//                 vps.pop();
//             }
//         }
//         if (empty_check && vps.size() == 0)
//         {
//             cout << "YES" <<endl;
//         }
//         else 
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }