#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
void getRandomNumber(vector<int>& randValue, int& pos)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
		randValue.push_back(rand() % 200);
	pos = rand() % 200;
}
//输入 请求访问序列和磁头所在位置
//输出 移动磁道数
void show(vector<int>& t)
{
	for (int i = 0; i < t.size(); i++)
	{
		if (i != t.size() - 1)
			cout << t[i] << "->";
		else
			cout << t[i] << endl;
	}
}
int FindLarger(vector<int>& t, int n)
{
	int l = 0;
	int r = t.size() - 1;

	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (t[mid] >= n)r = mid;
		else l = mid + 1;
	}
	return l;

}
//int FindSmaller(vector<int>& t, int n)
//{
//	int l = 0;
//	int r = t.size() - 1;
//	while (l < r)
//	{
//		int mid = (l + r + 1) >> 1;
//		if (t[mid] <= n)l = mid;
//		else r = mid - 1;
//	}
//	return l;
//}

int FCFS(vector<int> t, int pos)
{
	int sum = 0;
	cout << "FCFS的访问序列为:";
	show(t);
	for (int i = 0; i < t.size(); i++)
	{
		sum += t[i] > pos ? t[i] - pos : pos - t[i];
		pos = t[i];
	}
	cout << endl;
	return sum;
}
int SSTF(vector<int> t, int pos)
{
	vector<int> show;
	int sum = 0;
	sort(t.begin(), t.end());
	int n = FindLarger(t, pos);
	while (!t.empty())
	{
		
	}
}
int SCAN(vector<int> t, int pos)
{

}
int CSCAN(vector<int> t, int pos)
{

}
int FSCAN(vector<int> t, int pos)
{

}
int main()
{
	int pos = 0;
	vector<int> randValue;
	getRandomNumber(randValue, pos);

	cout << FCFS(randValue, pos) << endl;
	cout << SSTF(randValue, pos) << endl;


	return 0;
}