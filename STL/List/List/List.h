#pragma once
#include <iostream>
namespace gao
{
	template <class T>
	struct ListNode
	{
		ListNode(const T& value = T())
			:_prev(nullptr),
			_next(nullptr),
			_val(value)
		{

		}
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
	};
	template<class T,class Ref,class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		ListIterator(Node* pNode = nullptr)
		{
			_node = pNode;
		}
		Ref operator*()
		{
			return _node->_val;
		}
		Ptr operator->()
		{
			return &_node->_val;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_node = _node->_next;
			return temp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_node = _node->_prev;
			return temp;
		}
		bool operator!=(const Self& l)
		{
			return _node != l._node;
		}

		bool operator==(const Self& l)
		{
			return _node == l._node;

		}
		Node* _node;
	};
	template <class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, T&,T*> iterator;
		typedef ListIterator<T, const T&,const T*> const_iterator;

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			sz = 0;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		size_t size() const
		{
			return sz;
		}
		bool empty() const
		{
			if (sz == 0)
			{
				return true;
			}
			return false;
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		void push_back(const T& val)
		{
			insert(end(), val);
		}
		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* NewNode = new Node(val);
			Node* prev = cur->_prev;
			prev->_next = NewNode;
			NewNode->_prev = prev;
			NewNode->_next = cur;
			cur->_prev = NewNode;
			++sz;
			return NewNode;
		}
		iterator erase(iterator pos)
		{

		}
		~list()
		{

		}
	private:
		Node* _head;
		size_t sz;
	};

}