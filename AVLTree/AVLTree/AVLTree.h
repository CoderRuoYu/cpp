#pragma once
#include <assert.h>
#include <iostream>
template <class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K,V>& data)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_data(data),
		_bf(0)
	{
		;
	}
	AVLTreeNode(K key = K(), V value = V())
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_data(key, value),
		_bf(0)
	{
		;
	}
	struct AVLTreeNode<K, V>* _left;
	struct AVLTreeNode<K, V>* _right;
	struct AVLTreeNode<K, V>* _parent;
	pair<K, V> _data;
	int _bf;

};
template <class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
	AVLTree()
		:_root(nullptr)
	{
		;
	}
	bool insert(const pair<K, V>& data)
	{
		if (!_root)
		{
			_root = new Node(data);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (data.first > cur->_data.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (data.first < cur->_data.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (data.first < parent->_data.first)
		{
			cur = new Node(data);
			parent->_left = cur;
			cur->_parent = parent;
			parent->_bf--;
		}
		else
		{
			cur = new Node(data);
			parent->_right = cur;
			cur->_parent = parent;
			parent->_bf++;
		}
		while (parent != nullptr)
		{
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				Node* ppNode = parent->_parent;
				if (ppNode == nullptr)break;
				if (parent == ppNode->_left)
				{
					ppNode->_bf--;
				}
				else
				{
					ppNode->_bf++;
				}
				parent = ppNode;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				if (parent->_bf == 2 && parent->_right->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == 2 && parent->_right->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && parent->_left->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == -2 && parent->_left->_bf == -1)
				{
					RotateR(parent);
				}
				else
				{
					assert(false);
				}
			}
		}
		return true;
	}
	void RotateL(Node* parent)
	{
		Node* pright = parent->_right;
		Node* ppNode = parent->_parent;
		parent->_right = pright->_left;
		if (pright->_left)
		{
			pright->_left->_parent = parent;
		}
		pright->_left = parent;
		parent->_parent = pright;
		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = pright;
			}
			else
			{
				ppNode->_right = pright;
			}
		}
		else
		{
			_root = pright;
		}
		pright->_parent = ppNode;
		parent->_bf = 0;
		pright->_bf = 0;
	}
	void RotateR(Node* parent)
	{
		Node* pleft = parent->_left;
		Node* ppNode = parent->_parent;
		parent->_left = pleft->_right;
		if (pleft->_right)
		{
			pleft->_right->_parent = parent;
		}
		pleft->_right = parent;
		parent->_parent = pleft;
		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = pleft;
			}
			else
			{
				ppNode->_right = pleft;
			}
		}
		else
		{
			_root = pleft;
		}
		pleft->_parent = ppNode;
		parent->_bf = 0;
		pleft->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* pleft = parent->_left;
		Node* pleftRight = pleft->_right;
		int bf = pleftRight->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			pleft->_bf = -1;
			parent->_bf = 0;
			pleftRight->_bf = 0;
		}
		else if (bf == -1)
		{
			pleft->_bf = 0;
			parent->_bf = 1;
			pleftRight->_bf = 0;
		}
		else if (bf == 0)
		{
			pleft->_bf = 0;
			parent->_bf = 0;
			pleftRight->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(Node* parent)
	{
		
		Node* pright = parent->_right;
		Node* prightLeft = pright->_left;
		int bf = prightLeft->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			parent->_bf = -1;
			pright->_bf = 0;
			prightLeft->_bf = 0;
			
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			pright->_bf = 1;
			prightLeft->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			pright->_bf = 0;
			prightLeft->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}

	void printTree()
	{
		_print(_root);
		cout << endl;
	}
	bool IsAVLTree()
	{
		return _IsAVLTree(_root);
	}
private:
	bool _IsAVLTree(Node* root)
	{
		if (root == nullptr)return true;
		if (!_IsAVLTree(root->_left) || !_IsAVLTree(root->_right))return false;
		int left = _Height(root->_left);
		int right = _Height(root->_right);
		int balance_factor = right - left;
		if (abs(balance_factor) >= 2 || balance_factor != root->_bf)return false;
		return true;
	}
	size_t _Height(Node* root)
	{
		if (root == nullptr)return 0;
		int left = _Height(root->_left);
		int right = _Height(root->_right);
		return left >= right ? left + 1 : right + 1;
	}
	void _print(Node* root)
	{
		if (root == nullptr)return;
		_print(root->_left);
		cout << '(' << root->_data.first << ',' << root->_data.second << ") ";
		_print(root->_right);
	}
	Node* _root;
};
