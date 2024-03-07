#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"

void test01()
{
	BSTree<int, int> t;
	int arr[] = { 8,5,6,7,9,2,3,1,0 };
	for (auto e : arr)
	{
		t.Insert(e, e);
		t.InOrder();
	}
	/*t.Erase(8);
	t.InOrder();
	t.Erase(5);
	t.InOrder();*/
	for (auto e : arr)
	{
		t.Erase(e);
		t.InOrder();
	}
	t.InOrder();

}
int main()
{

	test01();
	return 0;
}