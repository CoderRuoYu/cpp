#pragma once
#include <iostream>
using namespace std;
template <class K,class V>
struct BinarySearchTreeNode
{
	BinarySearchTreeNode(const K& key = K(), const V& value = V())
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
		,_value(value)
	{
		;
	}
	struct BinarySearchTreeNode* _left;
	struct BinarySearchTreeNode* _right;
	K _key;
	V _value;
};
template <class K, class V>
class BSTree
{
public:
	typedef BinarySearchTreeNode<K, V> Node;
	BSTree()
		:_root(nullptr)
	{
		;
	}
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
		}
		else
		{
			Node* cur = _root;
			Node* parent = _root;
			while (cur)
			{
				if (cur->_key == key)return false;
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					parent = cur;
					cur = cur->_left;
				}
			}
			if (parent->_key < key)
			{
				Node* tmp = new Node(key, value);
				parent->_right = tmp;
			}
			else
			{
				Node* tmp = new Node(key, value);
				parent->_left = tmp;
			}
		}
		return true;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)return cur;
			else if (cur->_key > key)cur = cur->_left;
			else cur = cur->_right;
		}
		return cur;
	}
	bool Erase(const K& key)
	{
		if (_root == nullptr)return false;
		Node* parent = _root;
		Node* cur = _root;
		while (cur && cur->_key != key)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		if (cur)
		{

		}
		else
		{

		}
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)return;
		_InOrder(root->_left);
		cout << '(' << root->_key << ',' << root->_value << ')' << ' ';
		_InOrder(root->_right);
	}
private:

	Node* _root;
};