#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void AdjustDown(HPDataType* a, int size, int parents);
//创建堆
void HeapCreate(Heap* hp, HPDataType* a, int n);

//堆的销毁
void HeapDestory(Heap* hp);

//删除堆顶元素
void HeapPop(Heap* hp);


//取堆顶元素
HPDataType HeapTop(Heap* hp);
//判断堆是否为空
bool HeapEmpty(Heap* hp);
//返回堆的大小
int HeapSize(Heap* hp);