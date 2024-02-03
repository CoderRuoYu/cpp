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


}
int main()
{
	test01();
	return 0;
}