#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct function
{
	void operator()(int& a1, int a2)
	{
		a1 = a1 + a2;
	}
};
struct AbstractAdoptor
{
	AbstractAdoptor()
	{
		addfun = new function;
	}
	void operator()(int& v)
	{
		addfun->operator()(v, 10);
	}
	function* addfun;
};
int main()
{
	vector<int> t;
	for (int i = 0; i < 10; i++)t.push_back(i);
	for_each(t.begin(), t.end(), AbstractAdoptor());
	for (auto e : t)cout << e << ' ';
	return 0;
}