#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Button
{
public:
	virtual void display() = 0;
};
class MacButton :public Button
{
public:
	virtual void display()
	{
		cout << "This is a MacButton" << endl;
	}
};
class WindowsButton :public Button
{
public:
	virtual void display()
	{
		cout << "This is a WindowsButton" << endl;
	}
};
class Text
{
public:
	virtual void display() = 0;
};
class MacText :public Text
{
public:
	virtual void display()
	{
		cout << "This is a MacText" << endl;
	}
};
class WindowsText :public Text
{
public:
	virtual void display()
	{
		cout << "This is a WindowsText" << endl;
	}
};
class Factory
{
public:
	virtual Button* CreateButton() = 0;
	virtual Text* CreateText() = 0;
};
class MacFactory:public Factory
{
public:
	virtual Button* CreateButton()
	{
		return new MacButton();
	}
	virtual Text* CreateText()
	{
		return new MacText();

	}
};
class WindowsFactory:public Factory
{
public:
	virtual Button* CreateButton()
	{
		return new WindowsButton();

	}
	virtual Text* CreateText()
	{
		return new WindowsText();

	}
};
int main()
{
	Factory* f1 = new MacFactory();
	Button* mb = f1->CreateButton();
	mb->display();
	Text* mt = f1->CreateText();
	mt->display();
	delete f1;
	delete mt;
	delete mb;
	return 0;
}