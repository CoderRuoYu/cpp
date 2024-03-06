#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"

void test01()
{
	/*BSTree<int, int> cnt;
	cnt.Insert(1, 2);
	cnt.Insert(8, 2);
	cnt.Insert(5, 2);
	cnt.Insert(4, 2);
	cnt.Insert(-1, 2);
	cnt.InOrder();*/

	BSTree<string, string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "单词拼写错误" << endl;
		}
	}

}
int main()
{

	test01();
	return 0;
}