#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Tv
{
public:
	void On()
	{
		cout << "电视机打开" << endl;
	}
	void Off()
	{
		cout << "电视机关闭" << endl;
	}
};
class Light
{
public:
	void On()
	{
		cout << "灯打开" << endl;
	}
	void Off()
	{
		cout << "灯关闭" << endl;
	}
};
class KTV
{
public:
	KTV()
	{
		pLight = new Light;
		pTv = new Tv;
	}
	void On_KTV()
	{
		cout << "进入KTV模式" << endl;
		pLight->On();
		pTv->On();
	}
	void Off_KTV()
	{
		cout << "退出KTV模式" << endl;

		pLight->Off();
		pTv->Off();
	}
	~KTV()
	{
		delete pLight;
		delete pTv;
	}
private:
	Light* pLight;
	Tv* pTv;
};
int main()
{
	KTV* k = new KTV;
	k->On_KTV();
	k->Off_KTV();
	return 0;
}