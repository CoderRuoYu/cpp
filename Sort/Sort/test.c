#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void test01()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	ArryPrint(a, sizeof(a) / sizeof(int));

	InsertSort(a, sizeof(a) / sizeof(int));
	ArryPrint(a, sizeof(a) / sizeof(int));

}
int main()
{
	test01();
	return 0;
}



