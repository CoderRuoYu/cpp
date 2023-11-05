#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include "List.h"
#include <list>
using namespace std;

void test01()
{
	gao::list<int> test;
	test.push_front(1);
	test.push_front(2);
	test.push_front(3);
	test.push_front(4);
	test.push_back(9);
	test.push_back(10);
	test.push_back(11);
	test.push_back(12);
	gao::list<int>::iterator i = test.begin();
	while (i != test.end())
	{
		cout << *i << ' ';
		i++;
	}
	cout << endl;

	i = test.begin();
	for (int j = 0; j < 2; j++)
	{
		i++;
	}

	gao::list<int>::iterator temp = test.erase(i);



	gao::list<int>::iterator a = test.begin();
	while (a != test.end())
	{
		cout << *a << ' ';
		a++;
	}
	cout << endl;

	test.erase(temp);
	gao::list<int>::iterator b = test.begin();

	while (b != test.end())
	{
		cout << *b << ' ';
		b++;
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
	test03();
	
	return 0;
}