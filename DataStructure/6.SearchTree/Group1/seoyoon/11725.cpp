#include <iostream>
using namespace std;

int main()
{
	int num = 65;

	//int*���� char*������
	char* charPtr = reinterpret_cast<char*>(&num);
	cout << num << " to " << *charPtr << endl;

	return 0;
}