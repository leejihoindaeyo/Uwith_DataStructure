#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    //그냥 int형으로 할 시에 시간 복잡도가 너무 큼.  list를 이용해서 할시 시간 복잡도가 o(1)로 해결가능
    list<char>text(s.begin(),s.end());
     //문자열 s를 한 글자씩 list에 저장
    auto cursor = text.end();
    while(m--)
    {
        char input;
        cin >> input;

        if (input == 'L') {
            if (cursor != text.begin())
                cursor--; 
        }
        else if (input == 'D') {
            if (cursor != text.end())
                cursor++;
        }
        else if (input == 'B') {
            if (cursor != text.begin()) {
                cursor--;
                cursor = text.erase(cursor); 
            }
        }
        else if (input == 'P') {
            char PlusInput;
            cin >> PlusInput;
            cursor = text.insert(cursor, PlusInput); 
            cursor++;
        }
    }


    for (char c : text)
    {
        cout << c;
    }
    return 0;
}