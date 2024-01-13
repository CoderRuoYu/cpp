#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	BTDataType _val;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;
int main()
{
	BTNode* mainNode = new BTNode;
	BTNode* Node1 = new BTNode;
	BTNode* Node2 = new BTNode;
	BTNode* Node3 = new BTNode;
	BTNode* Node4 = new BTNode;

	mainNode->_left = Node1;
	mainNode->_right = Node4;
	mainNode->_val = '1';

	Node1->_left = Node2;
	Node1->_right = Node3;
	Node1->_val = '2';

	Node2->_left = nullptr;
	Node2->_right = nullptr;
	Node2->_val = '3';

	Node3->_left = nullptr;
	Node3->_right = nullptr;
	Node3->_val = '4';

	Node4->_left = nullptr;
	Node4->_right = nullptr;
	Node4->_val = '5';

	BinaryTreePrevOrder(mainNode);
	cout << endl;
	BinaryTreeInOrder(mainNode);
	cout << endl;

	BinaryTreePostOrder(mainNode);

	return 0;
}