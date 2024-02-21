#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public:
	virtual ~Person()
	{
		cout << "父类对象释放" << endl;
	}
};
class Student:public Person
{
public:
	~Student()
	{
		cout << "子类对象释放" << endl;
	}

};
void test()
{
	Person* p1 = new Person();
	Person* p2 = new Student();
	delete p1;
	delete p2;

}
int main()
{
	test();
	return 0;
}