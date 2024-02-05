#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//带头双向循环链表
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

//创建一个链表的一个节点
ListNode* BuyNode(LTDataType x);

//创建返回链表的头节点
ListNode* ListCreate();

// 双向链表打印
void ListPrint(ListNode* pHead);

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);

// 双向链表头删
void ListPopFront(ListNode* pHead);

// 双向链表尾删
void ListPopBack(ListNode* pHead);

// 双向链表销毁
void ListDestory(ListNode* pHead);