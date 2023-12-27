#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Animal
{
public:
	virtual void speak() = 0;
};
class Dog :public Animal
{
public:
	void speak()override
	{
		cout << "汪汪" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()override
	{
		cout << "喵喵" << endl;
	}
};
class Factory
{
public:
	virtual Animal* CreateAnimal() = 0;
};
class DogFactory:public Factory
{
public:
	virtual Animal* CreateAnimal()override
	{
		return new Dog();
	}
};
class CatFactory :public Factory
{
public:
	virtual Animal* CreateAnimal()override
	{
		return new Cat();
	}
};
int main()
{
	Factory* a1 = new DogFactory();
	Animal* dog = a1->CreateAnimal();
	dog->speak();
	delete a1;
	delete dog;
	Factory* a2 = new CatFactory();
	Animal* cat = a2->CreateAnimal();
	cat->speak();
	delete a2;
	delete cat;

	return 0;
}