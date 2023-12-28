#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
using namespace std;
class AbstractFiletype
{
public:
	virtual void decode(string name) = 0;
};
class avi :public AbstractFiletype
{
public:

	void decode(string name)
	{
		cout << "avi文件：" << name << endl;
	}
};
class mp4 :public AbstractFiletype
{
public:
	void decode(string name)
	{
		cout << "mp4文件：" << name << endl;
	}
};
class OS
{
public:
	OS(AbstractFiletype* filetype)
	{
		this->filetype = filetype;
	}
	virtual void play(string name) = 0;
protected:
	AbstractFiletype* filetype;
};
class MacOs :public OS
{
public:
	MacOs(AbstractFiletype* filetype)
		:OS(filetype)
	{

	}
	virtual void play(string name)
	{
		filetype->decode(name);
	}

};
class WinOs :public OS
{
public:
	WinOs(AbstractFiletype* filetype)
		:OS(filetype)
	{

	}
	virtual void play(string name)
	{
		filetype->decode(name);
	}
};
int main()
{
	OS* t = new MacOs(new avi);
	t->play("战狼");
	return 0;
}