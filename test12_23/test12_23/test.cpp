#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	multimap<int, int> test = { {1,1},{1,2} };
	for (multimap<int, int>::iterator i = test.begin(); i != test.end(); i++)
	{
		cout << i->first << ' ' << i->second << endl;
	}
	cout << test.count(1) << endl;
	return 0;
}