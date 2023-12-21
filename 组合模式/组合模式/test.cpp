#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Component
{
public:
	virtual void SendMessage(const string& message) = 0;
	virtual ~Component() = default;
};
class Group:public Component
{
public:
	Group(const string& name) :_name(name) {};
	void add(Component* a)
	{
		group.push_back(a);
	}
	void SendMessage(const string& message) override
	{
		cout << "Send message to group:" << _name << endl;
		for (auto& e : group)
		{
			e->SendMessage(message);
		}
	}
	~Group()
	{
		for (auto& e : group)
		{
			delete e;
		}
	}
private:
	string _name;
	vector<Component*> group;
};
class Person:public Component
{
public:
	Person(const string& name) :_name(name) {}
	void SendMessage(const string& message) override
	{
		cout << _name << ':' << message << endl;
	}
private:
	string _name;
};
using namespace std;
int main()
{
	Group* maingroup = new Group("group0");
	Group* group1 = new Group("group1");
	Person* p1 = new Person("Lily");
	Person* p2 = new Person("John");
	Person* p3 = new Person("Tom");
	group1->add(p1);
	group1->add(p2);
	maingroup->add(group1);
	maingroup->add(p3);

	maingroup->SendMessage("The price of  this coat has been reduced to 100$!!!");
	return 0;
}