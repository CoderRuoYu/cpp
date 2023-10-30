#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"


void test01(gao::string& s)
{
	cout << s << endl;
	gao::string tem(s);
	cout << tem << endl;
	for (int i = 0; i < tem.size(); i++)
	{
		cout << tem[i] << ' ';
	}
	s = tem;
}
void test02(gao::string& s)
{
	s.clear();
	s.push_back('a');
	cout << s << endl;
	s += '\0';
	s += "ssss";
	cout << s << endl;
}
void test03(gao::string& s)
{
	gao::string temp;
	temp = "hhh";
	temp.resize(1);
	cout << temp << endl;
	temp.resize(10, 'g');
	cout << temp << endl;
}
void test04()
{
	gao::string s1("abcde3");
	cin >> s1;
	cout << s1 << endl;
	cin >> s1;
	cout << s1 << endl;

}
int main()
{
	
	test04();
	return 0;
}