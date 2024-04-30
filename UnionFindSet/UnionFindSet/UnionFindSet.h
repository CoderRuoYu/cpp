#pragma once
class UnionFindSet
{
public:
	UnionFindSet(size_t N)
	{
		_ufs.resize(N, -1);
	}
	int FindInSet(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}
	bool InSameSet(int a, int b)
	{
		return FindInSet(a) == FindInSet(b);
	}
	bool Union(int a, int b)
	{
		int index1 = FindInSet(a);
		int index2 = FindInSet(b);
		if (index1 == index2)return false;
		_ufs[index1] += _ufs[index2];
		_ufs[index2] = index1;
		return true;
	}
	size_t Count()
	{
		int size = 0;
		for (auto e : _ufs)
		{
			if (e < 0)size++;
		}
		return size;
	}
private:
	vector<int> _ufs;
};
