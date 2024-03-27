#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "AVLTree.h"
void test01()
{
	AVLTree<int, int> t;
	t.insert(make_pair(30, 30));
	t.printTree();

	t.insert(make_pair(10, 40));
	t.insert(make_pair(0, 50));
	t.printTree();
}
int main()
{
	test01();
	return 0;
}