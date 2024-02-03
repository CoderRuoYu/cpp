#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
//创建一个链表的一个节点
ListNode* BuyNode(LTDataType x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	tmp->_data = x;
	tmp->_prev = NULL;
	tmp->_next = NULL;
	return tmp;
}

//创建返回链表的头节点
ListNode* ListCreate()
{
	ListNode* head = BuyNode(-1);
	head->_next = head;
	head->_prev = head;
	return head;
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	printf("head<->");
	while (cur != pHead)
	{
		printf("%d<->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;

}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyNode(x);

	newNode->_next = pos;
	pos->_prev = newNode;
	prev->_next = newNode;
	newNode->_prev = prev;

}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos-> _prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}



// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_next);
}


// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
}
