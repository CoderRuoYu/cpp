#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
#include "BitSet.h"
void test01()
{
	BitSet::bitset<100> t;
	t.set(99);
	t.set(10);
	t.set(1);
	cout << t.test(99) << endl;
	cout << t.test(10) << endl;
	cout << t.test(1) << endl;
	t.reset(10);
	t.reset(1);
	cout << t.test(99) << endl;
	cout << t.test(10) << endl;
	cout << t.test(1) << endl;
}
int main()
{
	test01();
	return 0;
}