#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <assert.h>
using namespace std;
namespace gao
{
	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue()
		{
			;
		}
		bool empty()const
		{
			return q.empty();
		}
		T& front()
		{
			assert(!empty());
			return q.front();
		}
		const T& front()const
		{
			assert(!empty());
			return q.front;
		}
		void pop()
		{
			q.pop_front();
		}
		void push(const T& val)
		{
			q.push_back(val);
		}
		size_t size()const
		{
			return q.size();
		}
	private:
		Con q;
	};
}
int main()
{
	gao::queue<int> test;
	cout << test.empty() << endl;
	for (int i = 0; i < 4; i++)test.push(i);
	for (int i = 0; i < 4; i++)
	{
		cout << test.front() << ' ';
		test.pop();
	}
	return 0;
}