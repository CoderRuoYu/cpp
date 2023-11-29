#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum;//统计缺页次数
class Opt
{
public:
	Opt(int num_blocks, int a[], int num_v)
		:plen(num_blocks),
		v(a, a + num_v) {}
	//在内存中返回true，否则返回false
	bool isInMemory(int x)
	{
		if (p.end() != find(p.begin(), p.end(), x))
		{
			return true;
		}
		return false;
	}
	void opt()
	{
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			//不在在内存中
			if (!isInMemory(v[i]))
			{
				sum++;
				//内存中还有空余位置
				if (p.size() < plen)
				{
					p.push_back(v[i]);
				}
				else
				{
					int index = 0;
					vector<int>::iterator max = v.begin() + i;
					for (int j = 0; j < p.size(); j++)
					{
						vector<int>::iterator temp = find(v.begin() + i , v.end(), p[j]);
						if (temp > max)
						{
							max = temp;
							index = j;
						}
					}
					p[index] = v[i];
				}
			}
		}
		cout << "缺页次数为:" << sum << endl;
		cout << "缺页率为:" << sum * 100.0 / v.size() << '%' << endl;
	}
private:
	vector<int> p; //已经在内存中的页面
	vector<int> v; //模拟将要读入的页面
	int plen; //分配内存块的长度
};
int main()
{
	int blocks = 3; //分配的内存块数
	int visit[12] = { 1,5,4,2,3,6,5,2,4,2,5,2 };
	Opt temp(blocks, visit, 12);
	temp.opt();
	return 0;
}