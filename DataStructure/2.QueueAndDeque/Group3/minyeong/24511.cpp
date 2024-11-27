#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N,n;
    cin >> n;
    deque<int>d;

    int sq[100000];

    for(int i=0; i < n; i++) cin >> sq[i];

    for (int i=0; i < n; i++)
    {
        int a;
        cin >> a;
        if(sq[i] == 0) d.push_back(a);
    }
    cin >> N;

    for(int i=0; i < N; i++)
    {
        int a;
        cin >> a;
        d.push_front(a);
        cout << d.back() << " ";
        d.pop_back();
    }

     //스택은 항상 자기 자신을 pop




    return 0;
}