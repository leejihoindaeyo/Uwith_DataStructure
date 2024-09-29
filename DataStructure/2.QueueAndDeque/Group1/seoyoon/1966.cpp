#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	//�׽�Ʈ ���̽� ��
	int t;
	cin >> t;

	while (t--)
	{
		//������ ���� ��ġ�� �ñ��� ������ �ε���
		int doc_num, find;
		cin >> doc_num >> find;

		queue<pair<int, int>> q;
		priority_queue<int> pq; //�켱���� ť�� ���� ���� ū ������� ����

		for (int i = 0; i < doc_num; i++)
		{
			int priority;
			cin >> priority;
			q.push({ i, priority }); //q�� ������ �ε����� �켱���� ������ ���� 
			pq.push(priority);
		}

		//�μ�� ������ ��
		int count = 0;
		bool found = false;

		while (!q.empty())
		{
			int index = q.front().first;
			int priority = q.front().second;
			q.pop();

			//�켱���� ť�� ���� �հ����� ������ ��ü���� ���� ū ��!
			if (priority == pq.top())
			{
				pq.pop();
				count++;

				//���� �μ�� ������ �ε����� find�� ���ٸ�
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