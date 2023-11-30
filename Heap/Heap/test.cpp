#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
//void AdjustDown(HPDataType* a, int size, int parents);
////创建堆
//void HeapCreate(Heap* hp, HPDataType* a, int n);
//
////堆的销毁
//void HeapDestory(Heap* hp);
//
////删除堆顶元素
//void HeapPop(Heap* hp);
//
//
////取堆顶元素
//HPDataType HeapTop(Heap* hp);
////判断堆是否为空
//bool HeapEmpty(Heap* hp);
////返回堆的大小
//int HeapSize(Heap* hp);
int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	Heap test;
	
	HeapCreate(&test, a, sizeof(a) / sizeof(a[0]));
	cout << HeapSize(&test) << endl;
	while(test._size)
	{
		cout << HeapTop(&test) << " ";
		HeapPop(&test);
	}
	HeapDestory(&test);
	return 0;
}