//19591 독특한 계산기

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

deque<long long> num;  // 사용하기 쉽게 전역변수 사용
deque<char> oper;

char Check(char op){ // 연산자 우선순위

    char result = 1;  // 곱하기 나누기

    if (op == '+' || op == '-'){  // 더하기 빼기
        result = -1;
    }

    return result;
}

long long left(char  op) {  // 연산자에 맞게 왼쪽 부분을 연산함
    long long result = 0;

    if(op == '+') result = num.front() + (*(num.begin()+1));  
    else if(op == '-') result = num.front() - (*(num.begin()+1));
    else if(op == '*') result = num.front() * (*(num.begin()+1));
    else if(op == '/') result = num.front() / (*(num.begin()+1));
    return result;
}

long long right(char  op) {  // 연산자에 맞게 오른쪽 부분을 연산함
    long long result = 0;

    if(op == '+') result = (*(num.end()-2)) + num.back();
    else if(op == '-') result = (*(num.end()-2)) - num.back();
    else if(op == '*') result = (*(num.end()-2)) * num.back();
    else if(op == '/') result = (*(num.end()-2)) / num.back();
    return result;
}

void removeL(long long & tmp) { // 왼쪽 부분 제거해주는 함수
	
    num.pop_front(); 
    num.pop_front();

    oper.pop_front();

    num.emplace_front(tmp);
}

void removeR(long long & tmp2) { // 오른쪽 부분 제거해주는 함수
    num.pop_back();
    num.pop_back();

    oper.pop_back();

    num.emplace_back(tmp2);
}


int main(void)
{
    ios::sync_with_stdio(0); // 시간부족 해결
    cin.tie(0);
    
    string str; //문자열
    cin >> str;

    long long tmp=0, tmp2=0;
    int i=0;
    bool isMinus = false; // 음수인지 빼기인지 구별해줌
    
    if(str[0] == '-') { // 음수 판독
        isMinus = true; 
        i = 1; 
    }
    
    for(;str[i]!=0;i++) { //수와 연산자 분리

        if(str[i] >= '0') { // 아스키 코드를 사용해서  "str[i] 이 숫자인 경우"를 의미한다
            tmp *= 10; // 자리수 밀어주기 
            tmp += str[i]-'0'; // '0'을 빼줘서 의미하는 숫자로 변환해준다.

        }

        else { // 연산자 나오면 초기화
            num.emplace_back(tmp);
            tmp = 0;
            oper.emplace_back(str[i]);
        }
    }
    //마지막으로 구해진 수를 덱에 넣어줌 -> 얘는 연산자가 없어서 안끝남.
    num.emplace_back(tmp); 
    tmp = 0;
    
    if(isMinus) num.front() *= -1; //처음이 - 이었다면
 
    char op1, op2;
    
    while(!oper.empty()) { //연산자가 남아 있는게 없다면 반복문을 종료합니다.
        op1 = Check(oper.front()); 
        op2 = Check(oper.back()); 
        
        tmp = left(oper.front()); 
        tmp2 = right(oper.back()); 
     
        if(op1 > op2) removeL(tmp); 

        else if(op1 < op2) removeR(tmp2); 

        else { //우선순위가 서로 같은 경우

            if(tmp >= tmp2) {
                removeL(tmp); 

            } else { 
                removeR(tmp2);
            }
        }
    }
    cout << num.front(); 

    return 0;
}
