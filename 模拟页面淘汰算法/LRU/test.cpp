#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
int sum;
class LRU
{
public:
	LRU(int blocks, int a[], int nv)
		:num_blocks(blocks),
		v(a, a + nv){}
	bool isInMemory(int x)
	{
		if (find(p.begin(), p.end(), x) != p.end())
		{
			return true;
		}
		return false;
	}
	void lru()
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
					int index = 0;
					vector<int>::iterator min = v.begin() + i;
					for (int j = 0; j < p.size(); j++)
					{
						vector<int>::iterator temp = find(v.begin(), v.begin() + i, p[j]);
						if (temp < min)
						{
							min = temp;
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
	vector<int> p;
	vector<int> v;
	int num_blocks;
};
int main()
{
	int blocks = 3;
	int visit[12] = { 1,5,4,2,3,6,5,2,4,2,5,2 };
	LRU temp(3, visit, 12);
	temp.lru();
	return 0;
}