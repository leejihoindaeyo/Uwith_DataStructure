#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	//테스트 케이스 수
	int t;
	cin >> t;

	while (t--)
	{
		//문서의 수와 위치가 궁금한 문서의 인덱스
		int doc_num, find;
		cin >> doc_num >> find;

		queue<pair<int, int>> q;
		priority_queue<int> pq; //우선순위 큐는 들어가는 값이 큰 순서대로 정렬

		for (int i = 0; i < doc_num; i++)
		{
			int priority;
			cin >> priority;
			q.push({ i, priority }); //q에 문서의 인덱스와 우선순위 쌍으로 저장 
			pq.push(priority);
		}

		//인쇄된 문서의 수
		int count = 0;
		bool found = false;

		while (!q.empty())
		{
			int index = q.front().first;
			int priority = q.front().second;
			q.pop();

			//우선순위 큐의 제일 앞값보다 같으면 전체에서 제일 큰 것!
			if (priority == pq.top())
			{
				pq.pop();
				count++;

				//현재 인쇄된 문서의 인덱스가 find와 같다면
				if (index == find)
				{
					cout << count << endl;
					found = true;
				}
			}
			else
			{
				q.push({ index, priority });
			}
		}
	}

	return 0;
}