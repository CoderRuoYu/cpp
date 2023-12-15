#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include "List.h"
#include <list>
#include "reverse_iterator.h"

void test01()
{
	gao::list<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(3);
	temp.push_back(3);
	for (gao::list<int>::reverse_iterator i = temp.rbegin(); i != temp.rend(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}
void test05()
{
	gao::list<gao::test> temp;
	temp.push_back(gao::test(0));
	temp.push_back(gao::test(1));
	temp.push_back(gao::test(2));
	for (gao::list<gao::test>::iterator i = temp.begin(); i != temp.end(); i++)
	{
		cout << i->a << ' ';
	}
	cout << endl;
}
void test02()
{
	gao::list<int> s1(5, 2);
	gao::list<int> s2(5, 3);
	gao::list<int>::iterator ptr1 = s1.begin();
	gao::list<int>::iterator ptr2 = s2.begin();
	while (ptr1 != s1.end())
	{
		cout << *ptr1 << ' ';
		ptr1++;
	}
	cout << endl;
	while (ptr2 != s2.end())
	{
		cout << *ptr2 << ' ';
		ptr2++;
	}
	cout << endl;
	s2.swap(s1);
	ptr1 = s1.begin();
	ptr2 = s2.begin();
	while (ptr1 != s1.end())
	{
		cout << *ptr1 << ' ';
		ptr1++;
	}
	cout << endl;
	while (ptr2 != s2.end())
	{
		cout << *ptr2 << ' ';
		ptr2++;
	}
	cout << endl;
}
void test03()
{
	int arr[] = { 1,2,3,4,5,6 };
	gao::list<int> temp(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	gao::list<int> temp1(temp);
	for (auto& e : temp1)
	{
		cout << e << ' ';
	}
	cout << endl;

	temp1 = temp;
	for (auto& e : temp1)
	{
		cout << e << ' ';
	}
	cout << endl;
}
int main()
{
	test05();
	
	return 0;
}