#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
void getNextArray(string& s, vector<int>& next)
{
	assert(s.size() > 1);
	int i = 0;
	int j = 0;
	next.push_back(0);
	for (i = 1; i < s.size(); i++)
	{
		if (s[i] == s[j + 1])
		{
			j++;
			next.push_back(j);
		}
		else
		{

		}
	}
}
//如果目标串中包含对应子串返回开头第一个字母的位置，否则返回-1
int Kmp(string& t, string& s, vector<int>& next)
{

}
int main()
{

	return 0;
}