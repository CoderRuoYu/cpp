#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Oberserve
{
public:
	virtual void Update(const string& news) = 0;
	virtual ~Oberserve() = default;
};
class Group :public Oberserve
{
public:
	void add(Oberserve* a)
	{
		Clients.push_back(a);
	}
	Group(const string & name):_name(name){}
	void Update(const string& news)
	{
		for (auto& e : Clients)
		{
			e->Update(news);
		}
	}
private:
	string _name;
	vector<Oberserve*> Clients;
};
class Client:public Oberserve
{

public:
	Client(const string& name)
		:_name(name) {};
	void Update(const string& news)
	{
		cout << _name << " has received " << news << endl;
	}
private:
	string _name;
};
class Shop
{
public:
	void add(Oberserve* a)
	{
		clients.push_back(a);
	}
	void erase(Oberserve* a)
	{
		auto e = find(clients.begin(), clients.end(), a);
		if (e != clients.end())clients.erase(e);
	}
	void SendMessage()
	{
		for (auto& e : clients)
		{
			e->Update(message);
		}
	}
	void notify(const string& news)
	{
		message = news;
		SendMessage();
	}
private:
	string message;
	vector<Oberserve*> clients;
};
int main()
{
	// 创建观察者
	Client client1("Alice");
	Client client2("Bob");
	Client client3("Charlie");

	// 创建一个组
	Group group("Group1");
	group.add(&client1);
	group.add(&client2);

	// 创建一个商店
	Shop shop;

	// 将观察者（客户和组）添加到商店
	shop.add(&client1);
	shop.add(&client2);
	shop.add(&client3);
	shop.add(&group);

	// 测试通知功能
	cout << "-------- 发送第一条消息 --------" << endl;
	shop.notify("新产品发布啦！");

	// 移除一个观察者
	shop.erase(&client3);

	// 再次测试通知功能
	cout << "-------- 发送第二条消息 --------" << endl;
	shop.notify("特别促销即将开始！");
	return 0;
}