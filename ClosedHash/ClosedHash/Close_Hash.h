#pragma once
namespace Close_Hash
{
	enum State
	{
		EMPTY,
		DELETE,
		EXIST
	};
	template <class K>
	class DefaultFunc
	{
	public:
		size_t operator()(const K& key)
		{
			return size_t(key);
		}
	};
	template<>
	class DefaultFunc<string>
	{
	public:
		size_t operator()(const string& key)
		{
			size_t res = 0;
			for (auto e : key)
			{
				res = res * 131 + e;
			}
			return res;
		}
	};
	template <class K, class V>
	struct Elem
	{
		State _state = EMPTY;
		pair<K, V> _val;
	};
	template <class K, class V, class HashFunc = DefaultFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_t.resize(10);
		}
		bool Insert(const pair<K, V>& data)
		{
			HashFunc func;
			if (((float)_size / (float)_t.size()) >= 0.7)
			{
				size_t newSize = _t.size() * 2;
				HashTable newTable;
				newTable._t.resize(newSize);
				for (auto& e : _t)
				{
					if (e._state == EXIST)
					{
						newTable.Insert(e._val);
					}
				}
				_t.swap(newTable._t);
			}
			size_t key = func(data.first) % _t.size();
			while (_t[key]._state == EXIST)
			{
				if (_t[key]._val.first == data.first)return false;
				key = (++key) % _t.size();
			}
			_t[key]._state = EXIST;
			_t[key]._val = data;
			_size++;
			return true;
		}
		Elem<K, V>* Find(const K& k)
		{
			HashFunc func;
			size_t key = func(k) % _t.size();
			while (_t[key]._state == EXIST || _t[key]._state == DELETE)
			{
				if (_t[key]._state == EXIST && k == _t[key]._val.first)
				{
					return &_t[key];
				}
				key = (++key) % _t.size();
			}
			return nullptr;
		}
		bool Erase(const K& k)
		{
			Elem<K, V>* pos = Find(k);
			if (pos == nullptr)return false;
			pos->_state = DELETE;
			_size--;
			return true;
		}
		size_t Size()
		{
			return _size;
		}

	private:
		vector<Elem<K, V>> _t;
		size_t _size = 0;
	};
}
