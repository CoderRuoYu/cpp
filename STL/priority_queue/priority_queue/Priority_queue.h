#pragma once
namespace gao
{
	template <class T>
	struct less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template <class T>
	struct greater
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};
	template <class T, class Container = vector<T>, class Compare = greater<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{
			;
		}
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:c(first,last)
		{
			//向下调整
			if (c.size() > 1)
			{
				for (int i = (c.size() - 1 - 1) / 2; i >= 0; i--)
				{
					AdjustDown(i);
				}
			}
		}
		bool empty()const
		{
			return c.empty();
		}
		size_t size()const
		{
			return c.size();
		}
		T& top()
		{
			return c[0];
		}
		void push(const T& x)
		{
			c.push_back(x);
			//向上调整
			AdjustUp(c.size() - 1);
		}
		void pop()
		{
			swap(c[0], c[c.size() - 1]);
			c.pop_back();
			AdjustDown(0);
		}
	private:
		void AdjustDown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
				{
					child = child + 1;
				}
				if (comp(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
				}
				else
				{
					break;
				}
				parent = child;
				child = parent * 2 + 1;
			}
		}
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (parent >= 0)
			{
				if (comp(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
				}
				else
				{
					break;
				}
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		Container c;
		Compare comp;
	};
}
