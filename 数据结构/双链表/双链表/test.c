#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"

void test01()
{
	ListNode* phead = ListCreate();
	ListPushBack(phead, 1);
	ListPrint(phead);

	ListPushBack(phead, 2);
	ListPrint(phead);

	ListPushBack(phead, 3);
	ListPrint(phead);

	ListPushFront(phead, 3);
	ListPushFront(phead, 2);
	ListPushFront(phead, 1);
	ListPrint(phead);

	ListErase(phead->_next);
	ListPrint(phead);
	ListErase(phead->_prev);
	ListPrint(phead);

	ListPopBack(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	struct ListNode* ea = ListFind(phead, 1);
	ListErase(ea);
	ListPrint(phead);

	ListDestory(phead);
}
int main()
{
	test01();
	return 0;
}