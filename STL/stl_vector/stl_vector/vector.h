#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
namespace gao
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
		{}
		vector(int n, const T& value = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = value;
			}
			_end = _start + n;
		}
		template <class Inputlterator>
		vector(Inputlterator first, Inputlterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_endOfStorage = _start + v.capacity();
			_end = _start + v.size();
		}
		vector<T>& operator=(vector<T> x)
		{
			swap(x);
			return *this;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				iterator temp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						temp[i] = _start[i];
					}
					delete _start;
				}
				_start = temp;
				_end = _start + sz;
				_endOfStorage = _start + n;
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _end = _endOfStorage = nullptr;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _end;
		}
		const_iterator cbegin()const
		{
			return _start;
		}
		const_iterator cend()const
		{
			return _end;
		}
		size_t size()const
		{
			return _end - _start;
		}
		size_t capacity()const
		{
			return _endOfStorage - _start;
		}
		void swap(vector<T>& x)
		{
			std::swap(_start, x._start);
			std::swap(_end, x._end);
			std::swap(_endOfStorage, x._endOfStorage);
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_end = _start + n;
			}
			else
			{
				reserve(n);
				while (_end != _start + n)
				{
					*_end = value;
					_end++;
				}
			}
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _end);
			if (_end == _endOfStorage)
			{
				size_t len = pos - _start;
				size_t new_capacity = _endOfStorage == 0 ? 4 : 2 * capacity();
				reserve(new_capacity);
				//解决迭代器失效
				pos = _start + len;
			}
			iterator end = _end - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_end;
			return pos;
		}
		void push_back(const T& x)
		{
			insert(_end, x);
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _end);
			iterator i = pos + 1;
			while (i != _end)
			{
				*(i - 1) = *i;
				i++;
			}
			_end--;
			return pos;
		}
		void pop_back()
		{
			erase(_end - 1);
		}
	private:
		iterator _start = nullptr;
		iterator _end = nullptr;
		iterator _endOfStorage = nullptr;
	};
}
