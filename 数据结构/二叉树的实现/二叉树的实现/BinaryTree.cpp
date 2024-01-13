#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

// 通过前序遍历的数组"123##4#5##67##8##"构建二叉树
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
//{
//	queue<BTDataType> temp;
//}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == nullptr)
	{
		return;
	}

}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == nullptr)return;
	cout << root->_val << ' ';
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == nullptr)return;
	
	BinaryTreeInOrder(root->_left);
	cout << root->_val << ' ';
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == nullptr)return;

	BinaryTreePostOrder(root->_left);
	
	BinaryTreePostOrder(root->_right);
	cout << root->_val << ' ';
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
