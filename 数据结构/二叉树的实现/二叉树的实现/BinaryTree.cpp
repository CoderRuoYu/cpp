#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

// 通过前序遍历的数组"123##4#5##67##8##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(*pi < n&& a != nullptr);
	if (a[*pi] == '#')
	{
		*pi += 1;
		return nullptr;
	}
	BTNode* temp = new BTNode;
	temp->_val = a[*pi];
	*pi += 1;
	temp->_left = BinaryTreeCreate(a, n, pi);
	temp->_right = BinaryTreeCreate(a, n, pi);
	return temp;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == nullptr)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	root = nullptr;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == nullptr)return 0;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == nullptr)return 0;
	else if (root->_left == nullptr && root->_right == nullptr)return 1;
	else
	{
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	}
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == nullptr)return 0;
	if (k == 1)return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点 按照层次遍历的方式找到第一个值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == nullptr)return nullptr;
	queue<BTNode*> temp;
	temp.push(root);
	while (!temp.empty())
	{
		BTNode* a = temp.front();
		temp.pop();
		if (a->_val == x)return a;
		if (a == nullptr)
		{
			continue;
		}
		temp.push(a->_left);
		temp.push(a->_right);
	}
	return nullptr;
}
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
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == nullptr)return;
	queue<BTNode*> temp;
	temp.push(root);
	while (!temp.empty())
	{
		BTNode* a = temp.front();
		temp.pop();
		if (a == nullptr)
		{
			continue;
		}
		temp.push(a->_left);
		temp.push(a-> _right);
		cout << a->_val << ' ';
	}
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	queue<BTNode*> temp;
	if(root)
	{
		temp.push(root);
	}
	while (!temp.empty())
	{
		BTNode* front = temp.front();
		temp.pop();
		if (front == nullptr)
		{
			break;
		}
		temp.push(front->_left);
		temp.push(front->_right);
	}
	while (!temp.empty())
	{
		BTNode* front = temp.front();
		if (front != nullptr)return false;
		temp.pop();
	}
	return true;
}
