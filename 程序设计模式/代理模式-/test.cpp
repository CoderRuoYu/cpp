#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class AbstractInterfence
{
public:
	virtual void run() = 0;

};
class System:public AbstractInterfence
{
public:
	void run()
	{
		cout << "系统运行" << endl;
	}
};
class proxySystem :public AbstractInterfence
{
public:
	proxySystem(string name, string word)
	{
		username = name;
		password = word;
		s = new System;
	}
	bool check()
	{
		return username == "1" && password == "2";
	}
	void run()
	{
		if (check())
		{
			s->run();
		}
		else
		{
			cout << "用户名或密码错误" << endl;
		}
	}
	~proxySystem()
	{
		if (s)
		{
			delete s;
		}
	}
private:
	string username;
	string password;
	System* s;
};

int main()
{
	proxySystem* a = new proxySystem("2", "2");
	a->run();
	delete a;
	return 0;
}