//#pragma once
enum Color
{
	RED,
	BLACK
};
template <class K,class V>
struct TreeNode
{
	TreeNode(const pair <K, V>& kv, const Color& mycolor = RED)
		:_data(kv)
		,_color(mycolor)
		,_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
	{
		;
	}
	pair <K, V> _data;
	Color _color;
	struct TreeNode* _parent;
	struct TreeNode* _left;
	struct TreeNode* _right;
};
template <class K,class V>
class RBTree
{
public:
	typedef struct TreeNode<K, V> Node;
	bool Insert(const pair<K, V>& data)
	{
		if (!_root)
		{
			_root = new Node(data, BLACK);
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
		}
		else
		{
			cur = new Node(data);
			parent->_right = cur;
			cur->_parent = parent;
		}
		while (parent && parent->_color == RED)
		{
			Node* granderparent = parent->_parent;
			if (parent == granderparent->_left)
			{
				Node* uncle = granderparent->_right;
				if (uncle == nullptr)
				{
					if (cur == parent->_left)
					{
						RotateR(granderparent);
						granderparent->_color = RED;
						parent->_color = BLACK;
					}
					else
					{
						RotateL(parent);
						RotateR(granderparent);
						cur->_color = BLACK;
						granderparent->_color = RED;
					}
					break;
				}
				else if (uncle->_color == RED)
				{
					uncle->_color = parent->_color = BLACK;
					granderparent->_color = RED;
					cur = granderparent;
					parent = cur->_parent;
				}
				else if (uncle->_color == BLACK)
				{
					if (cur == parent->_left)
					{
						RotateR(granderparent);
						granderparent->_color = RED;
						parent->_color = BLACK;
					}
					else
					{
						RotateL(parent);
						RotateR(granderparent);
						granderparent->_color = RED;
						cur->_color = BLACK;
					}
					break;
				}
			}
			else
			{
				Node* uncle = granderparent->_left;
				if (uncle == nullptr)
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						RotateL(granderparent);
						granderparent->_color = RED;
						cur->_color = BLACK;
					}
					else
					{
						RotateL(granderparent);
						parent->_color = BLACK;
						granderparent->_color = RED;
					}
					break;
				}
				else if (uncle->_color == RED)
				{
					uncle->_color = parent->_color = BLACK;
					granderparent->_color = RED;
					cur = granderparent;
					parent = cur->_parent;
				}
				else if (uncle->_color == BLACK)
				{
					if (cur == parent->_right)
					{
						RotateL(granderparent);
						granderparent->_color = RED;
						parent->_color = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(granderparent);
						granderparent->_color = RED;
						cur->_color = BLACK;
					}
					break;
				}
			}
			_root->_color = BLACK;
		}
		return true;
	}
	Node* find(const pair<K, V>& data)
	{
		if (_root == nullptr)return nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_data.first == data.first)
			{
				return cur;
			}
			else if (cur->_data.first < data.first)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return nullptr;
	}
	bool checkRED(Node* root)
	{
		if (root == nullptr)return true; 
		if (root->_color == RED && root->_parent && root->_parent->_color == RED)
		{
			return false;
		}
		return checkRED(root->_left) && checkRED(root->_right);
	}
	bool IsValidRBTree()
	{
		if (_root == nullptr)return true;
		//检测根节点是否是黑色
		if (_root->_color != BLACK)return false;
		//检查是否有连续的红色节点
		if (!checkRED(_root))return false;
		
		//统计一条路径上黑色节点的数目
		Node* cur = _root;
		size_t blacknumbers = 0;
		while (cur)
		{
			if (cur->_color == BLACK)blacknumbers++;
			cur = cur->_left;
		}
		size_t num = 0;
		return _isVaildRBTree(_root, blacknumbers, num);
		
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
	}
	
	void print()
	{
		_print(_root);
	}
private:
	void _print(Node* root)
	{
		if (root == nullptr)return;
		_print(root->_left);
		cout << '(' << root->_data.first << ',' << root->_data.second << ')' << "->";
		_print(root->_right);

	}
	bool _isVaildRBTree(Node* root, size_t blacknumbers, size_t num)
	{
		if (root == nullptr)
		{
			if (num == blacknumbers)return true;
			return false;
		}
		if (root->_color == BLACK)++num;
		return _isVaildRBTree(root->_left, blacknumbers, num) && _isVaildRBTree(root->_right, blacknumbers, num);
	}
	Node* _root = nullptr;
};
