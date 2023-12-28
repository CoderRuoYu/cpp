#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//懒汉式
//class Factory
//{
//public:
//	static Factory* GetInstance()
//	{
//		if (a == nullptr)
//		{
//			a = new Factory();
//		}
//		return a;
//	}
//private:
//
//	Factory()
//	{
//	}
//	static Factory* a;
//};
//Factory* Factory::a = nullptr;
//饥汉式
class Factory
{
public:
	static Factory* GetInstance()
	{
		return a;
	}
private:

	Factory()
	{
	}
	static Factory* a;
};
Factory* Factory::a = new Factory();
int main()
{
	Factory* test = Factory::GetInstance();
	Factory* test1 = Factory::GetInstance();
	cout << test << endl << test1 << endl;
	return 0;
}