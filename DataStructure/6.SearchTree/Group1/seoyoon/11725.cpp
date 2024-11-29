#include <iostream>
using namespace std;

int main()
{
	int num = 65;

	//int*형을 char*형으로
	char* charPtr = reinterpret_cast<char*>(&num);
	cout << num << " to " << *charPtr << endl;

	return 0;
}