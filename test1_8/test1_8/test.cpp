#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int cau(int n)
{
	if (n == 0)return 1;
	int sum = 1;
	for (int i = n; i >= 1; i--)
	{
		sum *= i;
	}
	return sum;
}
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a = 1, b = 2;
	printf("Swap1调用前：a = %d,b = %d\n", a, b);
	Swap1(a, b);
	printf("Swap1调用前：a = %d,b = %d\n", a, b);
	printf("-------------------------------\n");
	a = 1, b = 2;
	printf("Swap2调用前：a = %d,b = %d\n", a, b);
	Swap2(&a, &b);
	printf("Swap2调用前：a = %d,b = %d\n", a, b);
	return 0;
}