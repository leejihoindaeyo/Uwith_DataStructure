#include <iostream>
#include <deque>
using namespace std;

deque<int> que;
bool arr[100000];
int main() 
{
	//��Ÿ�ӿ��� ����
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //�ڷᱸ�� ����
	cin >> N;

	//�ڷᱸ���� �� �Է�
	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	//������ ���� �Է��ϱ�
	for (int i = 0; i < N; i++) 
	{
		int x; 
		cin >> x;
		//������ ��� �ǳʶ�
		if (arr[i]) 
			continue;
		que.push_back(x);
	}

	//������ ���� ����
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