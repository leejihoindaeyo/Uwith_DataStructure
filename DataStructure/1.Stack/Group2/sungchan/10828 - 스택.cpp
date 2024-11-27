#include <bits/stdc++.h>
using namespace std;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> arr;
  int a = 0;
  cin >> a;
  while(a--){
      string name;
      cin >> name;
      if(name == "push"){
        int input = 0;
        cin >> input; 
        arr.push(input);
      }
      else if(name == "pop"){
        if(arr.empty())
          cout << -1 << '\n';
        else{
          cout << arr.top() << '\n';
          arr.pop();
        }
      }
      else if(name == "top"){
        if(arr.empty())
          cout << -1 << '\n';
        else 
          cout << arr.top() << '\n';
      }
      else if(name == "size")
          cout << arr.size() << '\n';
      else if(name == "empty")
        cout << arr.empty() << '\n';
    }
  return 0;