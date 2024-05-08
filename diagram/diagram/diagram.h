#pragma once
#include <vector>
#include <map>
#include <string>
#include <climits>
namespace linkMatrix
{
	template <class V, class W, W MAX_W = INT_MAX, bool isDirectedGraph = false>
	class graph
	{
	public:
		//��һ�����飬����������Ҫ�洢���ٸ�����
		graph(V* arr, size_t n)
			:_vertexs(n),
			_matrix(n)
		{
			for (size_t i = 0; i < n; i++)
			{
				_vertexs[i] = arr[i];
				_vIndex[arr[i]] = i;
				_matrix[i].resize(n, MAX_W);
			}

		}
		void addEdge(const V& src, const V& dest, W weight)
		{
			size_t srci = GetIndex(src);
			size_t desti = GetIndex(dest);
			_matrix[srci][desti] = weight;
			if (!isDirectedGraph)
			{
				_matrix[desti][srci] = weight;
			}
		}
		size_t GetIndex(const V& vertex)
		{
			//typename��ʹ�ã������� ��ʹ��Ƕ������ʱ�����������еľ�̬��Ա�������е�һ������
			typename vector<V>::iterator t = find(_vertexs.begin(), _vertexs.end(), vertex);
			if (t == _vertexs.end())
			{
				perror("�ýڵ㲻����");
				return -1;
			}
			return _vIndex[*t];
		}
		void print()
		{
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << _vertexs[i] << ":" << GetIndex(_vertexs[i]) << endl;
			}
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				
				cout << i << ' ';
			}
			cout << endl;
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << i << ' ';
				for (auto e : _matrix[i])
				{
					if (e == MAX_W)cout << '*' << ' ';
					else cout << e << ' ';
				}
				cout << endl;
			}
			cout << endl;

		}
	private:
		vector<V> _vertexs;
		map<V, size_t> _vIndex;
		vector<vector<W>> _matrix;
	};
	void test01()
	{
		string arr[] = { "����","����","����","����" };
		graph<string, int , true> a(arr, sizeof(arr) / sizeof(arr[0]));
		a.addEdge("����", "����", 1);
		a.addEdge("����", "����", 2);
		a.addEdge("����", "����", 3);
		a.addEdge("����", "����", 3);
		a.addEdge("����", "����", 6);
		a.print();
	}
}
namespace linkTable
{
	template < class W>
	struct Edge
	{
		Edge(size_t desti, W weight, Edge* next = nullptr)
			:_desti(desti),
			_next(next),
			_weight(weight)
		{
			;
		}
		size_t _desti;
		Edge* _next;
		W _weight;
	};
	template <class V, class W, bool isDirectedGraph = false>
	class graph
	{
	public:
		typedef Edge<W> edge;
		graph(V* arr, size_t n)
			:_vertexs(n),
			_table(n, nullptr)
		{
			for (size_t i = 0; i < n; i++)
			{
				_vertexs[i] = arr[i];
				_vIndex[arr[i]] = i;
			}
		}
		void addEdge(const V& src, const V& dest, W weight)
		{
			size_t srci = GetIndex(src);
			size_t desti = GetIndex(dest);
			edge* tmp = new edge(desti, weight);
			tmp->_next = _table[srci];
			_table[srci] = tmp;
			if (!isDirectedGraph)
			{
				tmp = new edge(srci, weight);
				tmp->_next = _table[desti];
				_table[desti] = tmp;
			}
		}
		size_t GetIndex(const V& vertex)
		{
			//typename��ʹ�ã������� ��ʹ��Ƕ������ʱ�����������еľ�̬��Ա�������е�һ������
			typename vector<V>::iterator t = find(_vertexs.begin(), _vertexs.end(), vertex);
			if (t == _vertexs.end())
			{
				perror("�ýڵ㲻����");
				return -1;
			}
			return _vIndex[*t];
		}
		void print()
		{
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << _vertexs[i] << ":" << GetIndex(_vertexs[i]) << endl;
			}
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << i << "-->";
				edge* cur = _table[i];
				while (cur)
				{
					cout << cur->_desti << ':' << cur->_weight << "-->";
					cur = cur->_next;
				}
				cout << endl;
			}
			cout << endl;
		}
		~graph()
		{
			for (auto cur : _table)
			{
				while (cur)
				{
					edge* tmp = cur;
					cur = cur->_next;
					delete tmp;
				}
			}
		}
	private:
		vector<V> _vertexs;
		map<V, size_t> _vIndex;
		vector<edge*> _table;
	};
	void test01()
	{
		string arr[] = { "����","����","����","����" };
		graph<string, int,true> a(arr, sizeof(arr) / sizeof(arr[0]));
		a.addEdge("����", "����", 1);
		a.addEdge("����", "����", 2);
		a.addEdge("����", "����", 3);
		a.addEdge("����", "����", 6);
		a.print();
	}
}
