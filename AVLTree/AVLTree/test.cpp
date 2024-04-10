#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include "AVLTree.h"
void test01()
{
	AVLTree<int, int> t;
	int arr[] = { 8,4,5,6,2,4,5,9,10,22,-1 ,10000,20000,30000,50000,-2,-3,-6,-7,-8};
	for (auto e : arr)
	{
		t.insert(make_pair(e, e));
		cout << t.IsAVLTree() << endl;
	}
	t.IsAVLTree();

	t.printTree();
}
int main()
{
	test01();
	return 0;
}