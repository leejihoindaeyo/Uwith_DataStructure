#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map <int, int> n_numbers;

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		n_numbers[card]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int m_number;
		cin >> m_number;
		cout << n_numbers[m_number] << " ";
	}

	return 0;
}