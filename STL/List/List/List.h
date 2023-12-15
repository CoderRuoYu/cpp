#pragma once
#include <iostream>
#include "reverse_iterator.h"
#include <assert.h>
namespace gao
{
	struct test
	{
		test(int b = 0)
		{
			a = b;
		}
		int a = 0;
	};
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
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;
		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			sz = 0;
		}
		list()
		{
			empty_init();
		}
		list(int n, const T& value = T())
		{
			empty_init();
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const list<T>& l)
		{
			empty_init();
			for (auto& e : l)
			{
				push_back(e);
			}
		}
		list<T>& operator=(list<T> l)
		{
			swap(l);
			return *this;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		reverse_iterator rbegin()
		{
			return end();
		}
		reverse_iterator rend()
		{
			return iterator(_head->_next);
		}
		/*const_reverse_iterator rbegin()
		{
			return iterator(_head);
		}
		const_reverse_iterator rend()
		{
			return iterator(_head->_next);
		}*/
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
			return iterator(NewNode);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = cur-> _next;
			cur->_next->_prev = prev;
			delete cur;
			--sz;
			return iterator(prev->_next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		T& front()
		{
			assert(size() > 0);
			return *begin();
		}
		const T& front()const
		{
			assert(size() > 0);
			return *begin();
		}
		T& back()
		{
			assert(size() > 0);
			return *(--end());

		}
		const T& back()const
		{
			assert(size() > 0);
			return *(--end());
		}
		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
			std::swap(sz, l.sz);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			sz = 0;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t sz;
	};

}