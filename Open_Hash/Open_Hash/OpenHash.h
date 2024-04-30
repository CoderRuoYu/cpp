#pragma once
namespace OpenHash
{
	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}

			return hash;
		}
	};

	template<class K, class V>
	struct HashBucketNode
	{
		HashBucketNode(const pair<K, V>& data)
			: _pNext(nullptr), _data(data)
		{}
		HashBucketNode<K, V>* _pNext;
		pair<K, V> _data;
	};
	template<class K, class V, class HF = HashFunc<K>>
	class HashBucket
	{
		typedef HashBucketNode<K, V> Node;

	public:
		HashBucket(size_t capacity = 2)
			: _table(capacity)
			, _size(0)
		{}

		~HashBucket()
		{
			Clear();
		}

		// 哈希桶中的元素不能重复
		bool Insert(const pair<K, V>& data)
		{
			if (Find(data.first))return false;
			HF hashFunc;
			size_t pos = hashFunc(data.first) % _table.size();
			if ((float)_size / (float)_table.size() >= 0.7)
			{
				HashBucket<K, V> newBucket(_table.size() * 2);
				//插入指针
				// !!!!!!!!!!
				//这种方法会新开所有节点，并释放所有节点，造成浪费，可以复制循环外面的代码实现
				//！！！！！！！
				for (auto& cur : _table)
				{
					while (cur)
					{
						newBucket.Insert(cur->_data);
						cur = cur->_pNext;
					}
				}
				_table.swap(newBucket._table);
			}
			Node* newNode = new Node(data);
			newNode->_pNext = _table[pos];
			_table[pos] = newNode;
			_size++;
			return true;
		}

		// 删除哈希桶中为data的元素
		bool Erase(const K& key)
		{
			HF hashFunc;
			size_t pos =hashFunc(key) % _table.size();
			Node* cur = _table[pos];
			Node* parent = nullptr;
			while (cur && cur->_data.first != key)
			{
				parent = cur;
				cur = cur->_pNext;
			}
			if (cur == nullptr)return false;
			if (parent == nullptr)_table[pos] = nullptr;
			else parent->_pNext = nullptr;
			delete cur;
			_size--;
			return true;
		}

		Node* Find(const K& key)
		{
			HF hashFunc;
			size_t pos = hashFunc(key) % _table.size();
			Node* cur = _table[pos];
			while (cur)
			{
				if (cur->_data.first == key)
				{
					return cur;
				}
				cur = cur->_pNext;
			}
			return nullptr;
		}


		

		size_t Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}
	private:
		void Clear()
		{
			_size = 0;
			for (auto cur : _table)
			{
				Node* setNull = cur;
				while (cur)
				{
					Node* tmp = cur;
					cur = cur->_pNext;
					delete tmp;
				}
				setNull = nullptr;
			}
		}
		vector<Node*> _table;
		size_t _size;      
	};
}
