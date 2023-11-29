#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
int sum;
typedef struct page
{
	page(int v,int n)
	{
		visited = v;
		page_num = n;
	}
	int visited;
	int page_num;
}page;
class CLOCK
{
public:
	CLOCK(int blocks, int a[], int nv)
		:num_blocks(blocks),
		v(a, a + nv){}
	bool isInMemory(int x)
	{
		int flag = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i].page_num == x)
			{
				flag = 1;
				break;
			}
		}
		if (flag)return true;
		return false;

	}
	void clock()
	{
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (!isInMemory(v[i]))
			{
				sum++;
				if (p.size() < num_blocks)
				{
					int vi = 1;
					auto num = v[i];
					p.push_back(page(vi, num));
				}
				else
				{
					int index = 0;
					while (true)
					{
						if (p[index].visited == 0)
						{
							p[index].page_num = v[i];
							p[index].visited = 1;
							break;
						}
						else
						{
							p[index].visited = 0;
						}
						index = (index + 1) % num_blocks;
					}
				}
			}
		}
		cout << "缺页次数为:" << sum << endl;
		cout << "缺页率为:" << sum * 100.0 / v.size() << '%' << endl;
	}
private:
	vector<int> v;
	vector<page> p;
	int num_blocks;
};
int main()
{
	int blocks = 4;
	int visit[12] = { 4 ,3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5 };
	CLOCK temp(4, visit, 12);
	temp.clock();
	return 0;
}