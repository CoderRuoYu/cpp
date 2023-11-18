#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
void AdjustDown(HPDataType* a, int size, int parents)
{
	int child = parents * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child++;
		}
		//构造大堆
		if (a[child] > a[parents])
		{
			swap(a[child], a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_size = n;
	hp->_capacity = n;
	hp->_a = new HPDataType[n];
	memmove(hp->_a, a, n);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void HeapDestory(Heap* hp)
{
	delete[] hp->_a;
	hp->_a = nullptr;
	hp->_size = 0;
	hp->_capacity = 0;
	hp = nullptr;
}
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return true;
	}
	return false;
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp && hp->_size > 0);
	return hp->_a[0];
}


