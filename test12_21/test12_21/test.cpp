#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	void A_test()
	{
		cout << "A_test" << endl;
	}
	virtual ~A()
	{
		cout << "~A" << endl;
	}
};
class B:public A
{
public:

	~B()
	{
		cout << "~B" << endl;
	}
};
class C:public B
{
public:

	~C()
	{
		cout << "~C" << endl;
	}
};
int main()
{
	A* test;
	test = new C;
	test->A_test();
	delete test;

	return 0;
}