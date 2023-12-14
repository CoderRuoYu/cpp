#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define read(x) scanf("%d",&x)
int main()
{
	int n, q, k;
	read(n), read(q), read(k);
	vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		read(t[i]);
	}
	sort(t.begin(), t.end());
	int flag = 1;
	while (q--)
	{
		int tag;
		read(tag);
		if (tag == 2)
		{
			if (!flag)
			{
				sort(t.begin(), t.end());
				flag = 1;
			}
			
			int cn = 0;
			int i = 0, j = t.size() - 1;
			while (i < j)
			{
				if (t[i] + t[j] == k)
				{
					cn++;
					j--;
				}
				else if (t[i] + t[j] < k)
				{
					i++;
				}
				else
				{
					j--;
				}
			}
			
			cout << cn << endl;
		}
		else
		{
			flag = 0;
			int l, r, j;
			read(l), read(r), read(j);
			int z = 0, y = t.size() - 1;
			while (z < y)
			{
				int mid = (z + y) >> 1;
				if (t[mid] >= l)y = mid;
				else
				{
					z = mid + 1;
				}
			}
			for (int i = z; i < t.size(); i++)
			{
				if (t[i] <= r)t[i] = j;
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}