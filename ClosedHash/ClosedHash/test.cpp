#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#include "Close_Hash.h"
void test01()
{
	Close_Hash::HashTable<int, int> t1;
	int arr[] = { 0,1,2,3,4,5,6,7,11,8,9,10 };
	for (auto e : arr)
	{
		t1.Insert(make_pair(e, e));
	}
	t1.Erase(1);
	t1.Erase(2);
	t1.Erase(11);

}
void test02()
{
	Close_Hash::HashTable<string, string> dict;
	dict.Insert(make_pair("����", "insert"));
	dict.Insert(make_pair("�Ե�", "yes"));
	dict.Insert(make_pair("��", "no"));
	Close_Hash::Elem<string, string>* pos = dict.Find("�Ե�");
	cout << pos->_val.first << ' ' << pos->_val.second << endl;
	cout << dict.Erase("��") << endl;
	cout<<dict.Erase("��");

}
int main()
{
	test02();
	return 0;
}