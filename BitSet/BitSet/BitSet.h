#pragma once
namespace BitSet
{
	template <size_t N = 100>
	class bitset
	{
	public:
		bitset()
		{
			_a.resize(N / 32 + 1);
		}
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] |= 1 << j;
		}
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] &= ~(1 << j);
		}
		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			return _a[i] & (1 << j);
		}
	private:
		vector<int> _a;
	};
}
