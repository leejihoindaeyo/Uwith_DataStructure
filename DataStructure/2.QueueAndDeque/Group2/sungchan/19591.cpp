#include <bits/stdc++.h>
using namespace std;
string str;
typedef long long ll;
vector<ll> num;
deque<char> oper;
void INPUT(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
}
bool oper1(char c){
    return c=='*'||c=='/';
}
bool oper2(char c){
    return c=='+'||c=='-';
}
void Parsing(){

    string token = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(i && (oper1(str[i]) || oper2(str[i])))
            num.push_back(stoll(token)),
                    token = "",
                    oper.push_back(str[i]);
        else token += str[i];
    }num.push_back(stoll(token));
}
ll calc(ll a, ll b, char c){
    switch(c){
        case '*' : return a*b;
        case '/' : return a/b;
        case '+' : return a+b;
        case '-' : return a-b;
    }
}
void SOLVE(){
    Parsing();
    if(oper.empty()) cout << num[0];
    ll left = 0 , right = num.size()-1;
    while(!oper.empty()){
        if(oper.size() == 1){
            ll ans = calc(num[left],num[left+1],oper.front());
            cout << ans;
            return;
        }
        if(oper1(oper.front()) && oper2(oper.back())){
            num[left+1] = calc(num[left],num[left+1],oper.front());
            left++;
            oper.pop_front();
        }
        else if(oper2(oper.front()) && oper1(oper.back())){
            num[right-1] = calc(num[right-1],num[right],oper.back());
            right--;
            oper.pop_back();
        }
        else{
            ll tempL = calc(num[left],num[left+1],oper.front());
            ll tempR = calc(num[right-1],num[right],oper.back());
            if(tempL >= tempR)
                num[left+1] = tempL , left++ , oper.pop_front();
            else num[right-1] = tempR , right-- , oper.pop_back();
        }
    }
}
int main(){
    INPUT();
    SOLVE();
}