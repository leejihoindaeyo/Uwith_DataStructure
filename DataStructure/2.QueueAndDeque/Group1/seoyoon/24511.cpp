#include <iostream>
#include <deque>
using namespace std;

deque<int> que;
bool arr[100000];
int main() 
{
	//런타임에러 방지
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //자료구조 개수
	cin >> N;

	//자료구조의 값 입력
	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	//삽입할 원소 입력하기
	for (int i = 0; i < N; i++) 
	{
		int x; 
		cin >> x;
		//스택일 경우 건너뜀
		if (arr[i]) 
			continue;
		que.push_back(x);
	}

	//삽입할 원소 개수
	int M; 
	cin >> M;
	while (M--) 
	{
		int x; 
		cin >> x;
		que.push_front(x);
		cout << que.back() << ' ';
		que.pop_back();
	}
}