#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <assert.h>
using namespace std;
namespace gao
{
	template <class T, class Con = deque<T>>
	class stack
	{
	public:
		stack()
		{

		}
		bool empty()
		{
			return s.empty();
		}
		void pop()
		{
			s.pop_back();
		}
		void push(const T& val)
		{
			s.push_back(val);
		}
		size_t size()const
		{
			return s.size();
		}
		T& top()
		{
			assert(!empty());
			return s.back();
		}
		const T& top()const
		{
			assert(!empty());
			return s.back();
		}
	private:
		Con s;
	};
}
int main()
{
	gao::stack<int> test;
	cout << test.empty() << endl;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	cout << test.empty() << endl;
	while (!test.empty())
	{
		cout << test.top() << ' ';
		test.pop();
	}
	return 0;
}