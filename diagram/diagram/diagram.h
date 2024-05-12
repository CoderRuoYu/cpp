#pragma once
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <queue>
namespace linkMatrix
{
	template <class W>
	struct Edge
	{
		Edge(size_t src,size_t dest,W weight)
			:_srci(src),
			_desti(dest),
			_weight(weight)
		{}
		size_t _srci;
		size_t _desti;
		W _weight;
	};
	template <class V, class W, W MAX_W = INT_MAX, bool isDirectedGraph = false>
	class graph
	{
	public:
		//给一个数组，并告诉我需要存储多少个顶点
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
			//typename的使用！！！！ 在使用嵌套类型时，区分是类中的静态成员还是类中的一个类型
			typename vector<V>::iterator t = find(_vertexs.begin(), _vertexs.end(), vertex);
			if (t == _vertexs.end())
			{
				perror("该节点不存在");
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
		void BFS(const V& src)
		{
			vector<size_t> visited(_vertexs.size(), 0);
			queue<size_t> q;
			size_t srci = _vIndex.at(src);
			q.push(srci);
			visited[srci] = 1;
			size_t cn = 0;
			while (!q.empty())
			{
				srci = q.front();
				q.pop();
				cout << srci << ':' << _vertexs[srci] << endl;
				cn++;
				for (size_t i = 0; i < _vertexs.size(); i++)
				{
					if (_matrix[srci][i] != MAX_W && visited[i] != 1)
					{
						q.push(i);
						visited[i] = 1;
					}
				}
				if (q.empty() && cn != _vertexs.size())
				{
					for (size_t i = 0; i < _vertexs.size(); i++)
					{
						if (visited[i] == 0)
						{
							q.push(i);
							visited[i] = 1;

							break;
						}
					}
				}
			}
		}
		void _DFS(size_t srci, vector<bool>& visited,size_t& cn)
		{
			visited[srci] = true;
			cn++;
			cout << srci << ':' << _vertexs[srci] << endl;
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				if (_matrix[srci][i] != MAX_W && visited[i] != true)
				{
					_DFS(i, visited,cn);
				}
			}
		}
		void DFS(const V& src)
		{
			vector<bool> visited(_vertexs.size(), false);
			size_t srci = _vIndex.at(src);
			size_t cn = 0;
			_DFS(srci, visited,cn);
			while (cn != visited.size())
			{
				for (size_t i = 0; i < visited.size(); i++)
				{
					if (visited[i] == false)
					{
						_DFS(i, visited, cn);
					}
				}
			}
		}
		W kruskal()
		{

		}
	private:
		vector<V> _vertexs;
		map<V, size_t> _vIndex;
		vector<vector<W>> _matrix;
	};
	void test01()
	{
		string arr[] = { "张三","李四","王五","麻子" ,"刘思" };
		graph<string, int ,INT_MAX,true> a(arr, sizeof(arr) / sizeof(arr[0]));
		a.addEdge("张三", "李四", 3);
		a.addEdge("张三", "王五", 3);
		a.addEdge("张三", "麻子", 3);
		a.addEdge("麻子", "张三", 3);
		a.addEdge("王五", "麻子", 3);
		a.print();
		a.DFS("刘思");
		
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
			//typename的使用！！！！ 在使用嵌套类型时，区分是类中的静态成员还是类中的一个类型
			typename vector<V>::iterator t = find(_vertexs.begin(), _vertexs.end(), vertex);
			if (t == _vertexs.end())
			{
				perror("该节点不存在");
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
		string arr[] = { "张三","李四","王五","麻子" };
		graph<string, int,true> a(arr, sizeof(arr) / sizeof(arr[0]));
		a.addEdge("张三", "李四", 1);
		a.addEdge("张三", "王五", 2);
		a.addEdge("张三", "麻子", 3);
		a.addEdge("麻子", "王五", 6);
		a.print();
	}
}
