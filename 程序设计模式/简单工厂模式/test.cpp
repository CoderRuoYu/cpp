#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Product
{
public:
	virtual void display() = 0;
};
class ProductA:public Product
{
public:
	virtual void display()
	{
		cout << "这是产品A" << endl;
	}

	ProductA()
	{
		cout << "正在创建一个产品A" << endl;
	}
};
class ProductB :public Product
{
public:
	virtual void display()
	{
		cout << "这是产品B" << endl;
	}
	ProductB()
	{
		cout << "正在创建一个产品B" << endl;
	}
};
class Factory
{
public:
	static Product* CreateProduct(string type)
	{
		if (type == "A")
		{
			return new ProductA;
		}
		else if(type == "B")
		{
			return new ProductB;
		}
		else
		{
			cout << "不存在这个对象" << endl;
			return nullptr;
		}
	}
};
int main()
{
	Product* test = nullptr;
	test = Factory::CreateProduct("A");
	test->display();
	test = Factory::CreateProduct("B");
	test->display();
	test = Factory::CreateProduct("C");
	return 0;
}