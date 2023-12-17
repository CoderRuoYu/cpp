#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
template <class T>
bool Less(T a, T b)
{
	return a < b;
}
template<>
bool Less(int* a, int* b)
{
	return *a < *b;
}
int main()
{
	int x = 1;
	int y = 2;
	cout << Less(&x, &y) << endl;
	cout << Less(1.0, -2.0) << endl;

	return 0;
}