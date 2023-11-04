#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
#include <list>
using namespace std;

void test01()
{
	gao::list<int> s;
	/*s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);*/
	gao::list<int>::const_iterator i = s.begin();

	list<int> t = { 1,2,3 };
	list<int>::const_iterator i = t.begin();
	while (i != t.end())
	{
		cout << *i << ' ';
		i++;
	}
}


int main()
{
	test01();
	
	return 0;
}