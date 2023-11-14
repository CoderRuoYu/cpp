#pragma once
#include <iostream>
using namespace std;
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void HeapCreate(Heap* hp,)
