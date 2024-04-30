#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
#include "UnionFindSet.h";
void test01()
{
	UnionFindSet t(10);
	t.Union(0, 5);
	t.Union(5,6);
	cout << t.FindInSet(5) << endl;
	cout << t.FindInSet(7) << endl;
	cout << t.InSameSet(5, 6) << endl;
	cout << t.InSameSet(0, 6) << endl;
	cout << t.InSameSet(2, 6) << endl;
	cout<<t.Count();

}
int main()
{
	test01();
	return 0;
}