#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <vector>
#include <functional>
#include "Priority_queue.h"
void test01()
{
	gao::priority_queue<int> t;
	cout << t.empty() << endl;
	cout << t.size() << endl;
}
void test02()
{
	int arr[] = { 8,5,7,3,6,9,12,20 };
	gao::priority_queue<int> t(arr, arr + sizeof(arr) / sizeof(arr[0]));
	t.push(-44);
	t.push(44);
	while (!t.empty())
	{
		cout << t.top() << ' ';
		t.pop();
	}
}
void test03()
{
	int arr[] = { 8,5,7,3,6,9,12,20 };
	gao::priority_queue<int, vector<int>, gao::greater<int>> t(arr, arr + sizeof(arr) / sizeof(arr[0]));
	t.push(-44);
	t.push(44);
	while (!t.empty())
	{
		cout << t.top() << ' ';
		t.pop();
	}

}
int main()
{
	test03();

	return 0;
}