#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <utility>
using namespace std;
#include "RedBlackTree.h"
void test01()
{
	int a[] = { 1,2,3,4,5,6,-1,-2,-3,-4 };
	RBTree<int, int> test;
	for (auto e : a)
	{
		test.Insert(make_pair(e,e));
		cout << e<<' ';
		cout << test.IsValidRBTree() << endl;
	}
	test.print();

}
int main()
{
	test01();
	return 0;
}
