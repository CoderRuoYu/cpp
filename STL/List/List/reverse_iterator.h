#pragma once
namespace gao
{
	template <class iterator,class Ref,class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<iterator,Ref,Ptr> self;
		iterator _it;
		Reverse_iterator(iterator temp)
		{
			_it = temp;
		}
		Ref operator*()
		{
			iterator temp = _it;
			--temp;
			return *temp;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		self& operator++()
		{
			_it--;
			return _it;
		}
		self operator++(int)
		{
			iterator temp = _it;
			_it--;
			return temp;
		}
		self& operator--()
		{
			return ++_it;
		}
		self operator--(int)
		{
			iterator temp = _it;
			_it++;
			return temp;
		}
		bool operator==(const self& temp)
		{
			return _it == temp._it;
		}
		bool operator!=(const self& temp)
		{
			return _it != temp._it;
		}
	};
}