#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Stratgy
{
public:
	virtual void show() = 0;

};
class StratgyA:public Stratgy
{
public:
	virtual void show()
	{
		cout << "买一送一" << endl;
	}
};
class StratgyB:public Stratgy
{
public:
	virtual void show()
	{
		cout << "满二百减五十" << endl;
	}
};
class Client
{
public:
	Client(Stratgy* t)
	{
		s = t;
	}
	void displapy()
	{
		s->show();
	}
	~Client()
	{
		delete s;
	}
private:
	Stratgy* s;
};
int main()
{
	Client s(new StratgyB);
	s.displapy();

	return 0;
}