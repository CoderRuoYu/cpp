#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int sum;
class FIFO
{
public:
	FIFO(int blocks, int visit[], int nv)
		:num_blocks(blocks),
		v(visit, visit + nv){}

	bool isInMemory(int x)
	{
		if (p.end() != find(p.begin(), p.end(), x))
		{
			return true;
		}
		return false;
	}
	void fifo()
	{
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (!isInMemory(v[i]))
			{
				sum++;
				if (p.size() < num_blocks)
				{
					p.push_back(v[i]);
				}
				else
				{
					p.pop_front();
					p.push_back(v[i]);
				}
			}
		}
		cout << "缺页次数为:" << sum << endl;
		cout << "缺页率为:" << sum * 100.0 / v.size() << '%' << endl;
	}
private:
	vector<int> v;//将要访问的页面
	deque<int> p;//内存中的页面
	int num_blocks;//分配的内存块数
};
int main()
{
	int blocks = 3;
	int visit[12] = { 1,5,4,2,3,6,5,2,4,2,5,2 };
	FIFO temp(blocks, visit, 12);
	temp.fifo();
	return 0;
}