// #include <iostream>
// #include <stack>
// using namespace std;

// int main(void)
// {
//     stack<int> num;
//     string command;
//     int n;
//     int a;
//     int result;

//     cin >> n;
//     for (int i=0; i < n; i++)
//     {
//         cin >> command;
//         if (command == "push")
//         {
//             cin >> a;
//             num.push(a);
//         }
//         else if(command == "pop")
//         {
//             if(num.size() == 0)
//             {
//                 result = -1;
//                 cout << result << endl;
//             }
//             else
//             {
//                 result = num.top();
//                 num.pop();
//                 cout << result << endl ;
//             }
//         }
//         else if (command == "size")
//         {
//             result = num.size();
//             cout << result << endl;
            
//         }
//         else if (command == "empty")
//         {
//             if(num.size() == 0)
//             {
//                 result = 1;
//                 cout << result << endl;
//             }
//             else
//             {
//                 result = 0;
//                 cout << result << endl;
//             }
//         }
//         else if (command == "top")
//         {
//             if (num.size() == 0)
//             {
//                 result = -1;
//                 cout << result << endl;
//             }
//             else
//             {
//                 result = num.top();
//                 cout << result << endl;
//             }
//         }
//     }

//     return 0;
// }


