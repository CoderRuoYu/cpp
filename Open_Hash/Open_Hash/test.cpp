#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#include "OpenHash.h"
void test01()
{
	int arr[] = { 0,1,2,1,5,6 };
	OpenHash::HashBucket<int, int> tem;
	for (auto& e : arr)
	{
		tem.Insert(make_pair(e, e));
	}
}
int main()
{
	test01();
	return 0;
}