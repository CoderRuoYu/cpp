#pragma once
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <queue>
#include <set>
#include <assert.h>
#include <string>
namespace linkMatrix
{
	class UnionFindSet
	{
	public:
		UnionFindSet(size_t N)
		{
			_ufs.resize(N, -1);
		}
		int FindInSet(int x)
		{
			while (_ufs[x] >= 0)
			{
				x = _ufs[x];
			}
			return x;
		}
		bool InSameSet(int a, int b)
		{
			return FindInSet(a) == FindInSet(b);
		}
		bool Union(int a, int b)
		{
			int index1 = FindInSet(a);
			int index2 = FindInSet(b);
			if (index1 == index2)return false;
			_ufs[index1] += _ufs[index2];
			_ufs[index2] = index1;
			return true;
		}
		size_t Count()
		{
			int size = 0;
			for (auto e : _ufs)
			{
				if (e < 0)size++;
			}
			return size;
		}
	private:
		vector<int> _ufs;
	};

	template <class W>
	struct Edge
	{
		Edge(size_t src,size_t dest,W weight)
			:_srci(src),
			_desti(dest),
			_weight(weight)
		{}
		bool operator>(const Edge<W>& compare)const
		{
			return _weight > compare._weight;
		}
		size_t _srci;
		size_t _desti;
		W _weight;
	};
	template <class V, class W, W MAX_W = INT_MAX, bool isDirectedGraph = false>
	class graph
	{
	public:
		//给一个数组，并告诉我需要存储多少个顶点
		graph(const V* arr, size_t n)
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
		graph()
		{}
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
		W kruskal(graph<V, W, MAX_W, isDirectedGraph>& res)
		{
			size_t n = _vertexs.size();
			res._vertexs = _vertexs;
			res._vIndex = _vIndex;
			res._matrix.resize(n);
			for (int i = 0; i < n; i++)
			{
				res._matrix[i].resize(n, MAX_W);
			}
			priority_queue<Edge<W>, vector<Edge<W>>, greater<Edge<W>>> q;
			UnionFindSet u(n);
			//选取最短路径
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					if (_matrix[i][j] != MAX_W)
					{
						q.push(Edge<W>(i, j, _matrix[i][j]));
					}
				}
			}
			//对节点处理
			W weight = W();
			size_t cn = n - 1;
			Edge<W> minW = q.top();
			q.pop();
			weight += minW._weight;
			cn--;
			res.addEdge(res._vertexs[minW._srci], res._vertexs[minW._desti], minW._weight);
			u.Union(minW._srci, minW._desti);

			while (!q.empty() && cn)
			{
				minW = q.top();
				q.pop();
				if (!u.InSameSet(minW._srci, minW._desti))
				{
					cn--;
					weight += minW._weight;
					res.addEdge(res._vertexs[minW._srci], res._vertexs[minW._desti], minW._weight);
					u.Union(minW._srci, minW._desti);
				}
			}
			if (cn == 0)return weight;
			else return W();
		}
		W Prim(const V& src, graph<V, W, MAX_W, isDirectedGraph>& res)
		{
			size_t srci = _vIndex[src];
			size_t n = _vertexs.size();
			//设置两个set，一个set用于作为已经选取源节点的顶点，另一个set用于作为还未在连通图中的节点
			set<size_t> X;
			set<size_t> Y;
			X.insert(srci);
			for (size_t i = 0; i < n; i++)
			{
				if (i != srci)
				{
					Y.insert(i);
				}
			}
			res._vertexs = _vertexs;
			res._vIndex = _vIndex;
			res._matrix.resize(n);
			for (int i = 0; i < n; i++)
			{
				res._matrix[i].resize(n, MAX_W);
			}
			priority_queue<Edge<W>, vector<Edge<W>>, greater<Edge<W>>> q;
			for (int i = 0; i < n; i++)
			{
				if (_matrix[srci][i] != MAX_W)
				q.push(Edge<W>(srci, i, _matrix[srci][i]));
			}
			W weight = W();
			size_t cn = n - 1;
			Edge<W> minE = q.top();
			q.pop();
			res.addEdge(res._vertexs[minE._srci], res._vertexs[minE._desti], minE._weight);
			cn--;
			weight += minE._weight;
			X.insert(minE._desti);
			Y.erase(minE._desti);
			for (int i = 0; i < n; i++)
			{
				if (_matrix[minE._desti][i] != MAX_W && X.count(i) == 0)
				{
					q.push(Edge<W>(minE._desti, i, _matrix[minE._desti][i]));
				}
				
			}
			
			while (!q.empty() && cn)
			{
				Edge<W> minE = q.top();
				q.pop();
				if (X.count(minE._srci) == 1 && Y.count(minE._desti) == 1)
				{
					
					res.addEdge(res._vertexs[minE._srci], res._vertexs[minE._desti], minE._weight);

					cn--;
					weight += minE._weight;
					X.insert(minE._desti);
					Y.erase(minE._desti);
					for (int i = 0; i < n; i++)
					{
						if (_matrix[minE._desti][i] != MAX_W && X.count(i) == 0)
						{
							q.push(Edge<W>(minE._desti, i, _matrix[minE._desti][i]));
						}
							
					}
				}
			}
			if (cn == 0)return weight;
			else return W();
		}
		//一般用于有向图
		//传入一个顶点，求这个顶点到其它顶点的最短路径
		void Dijkstra(const V& src, vector<W>& weight, vector<int>& shortest_path)
		{
			const size_t n = _vertexs.size();
			size_t srci = _vIndex[src];
			weight.resize(n, MAX_W);
			shortest_path.resize(n, -1);
			size_t cn = n;
			//声明一个数组，用于确认这个点的最短路径是否已经确认
			vector<bool> vConfirm(n, false);

			//源节点到自己的最短路径已经找到
			weight[srci] = W();
			shortest_path[srci] = -1;
			while (cn != 0)
			{
				int curi = -1;
				int min = MAX_W;
				for (size_t i = 0; i < n; i++)
				{
					if (weight[i] != MAX_W && vConfirm[i] == false && weight[i] < min)
					{
						curi = i;
						min = weight[i];
					}
				}
				if (curi == -1)
				{
					cout << "该图是非连通图" << endl;
					assert(false);
					return;
				}
				else
				{
					vConfirm[curi] = true;
					cn--;
				}
				for (size_t i = 0; i < n; i++)
				{
					if (vConfirm[i] == false && _matrix[curi][i] != MAX_W && weight[curi] + _matrix[curi][i] < weight[i])
					{
						weight[i] = weight[curi] + _matrix[curi][i];
						shortest_path[i] = curi;
					}
				}
			}
		}
		// 打印最短路径的逻辑算法
		void PrinrtShotPath(const V& src, const vector<W>& dist, const vector<int>&
			parentPath)
		{
			size_t N = _vertexs.size();
			size_t srci = _vIndex[src];
			for (size_t i = 0; i < N; ++i)
			{
				if (i == srci)
					continue;

				vector<int> path;
				int parenti = i;
				while (parenti != srci)
				{
					path.push_back(parenti);
					parenti = parentPath[parenti];
				}
				path.push_back(srci);
				reverse(path.begin(), path.end());
				for (auto pos : path)
				{
					cout << _vertexs[pos] << "->";
				}
				cout << ":" << dist[i] << endl;
			}
		}
		//求最短路径并可以解决负权路径问题
		bool Bellman_Ford(const V& src, vector<W>& dist, vector<int>& shortest_path)
		{
			int srci = _vIndex[src];
			const size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			shortest_path.resize(n, -1);
			dist[srci] = W();
			shortest_path[srci] = -1;
			for (int cn = 0; cn < n - 1; cn++)
			{
				bool flag = false;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (_matrix[i][j] != MAX_W && dist[i] != MAX_W && _matrix[i][j] + dist[i] < dist[j])
						{
							flag = true;
							dist[j] = _matrix[i][j] + dist[i];
							shortest_path[j] = i;
						}
					}
				}
				if (!flag)break;
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (_matrix[i][j] != MAX_W && dist[i] != MAX_W && _matrix[i][j] + dist[i] < dist[j])
					{
						return false;
					}
				}
			}
			return true;
		}
		void FloydWarShall(vector<vector<W>>& vvDist, vector<vector<int>>& vvpPath)
		{
			const size_t n = _vertexs.size();
			vvDist.resize(n);
			vvpPath.resize(n);
			for (int i = 0; i < n; i++)
			{
				vvDist[i].resize(n, MAX_W);
				vvpPath[i].resize(n, -1);
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvDist[i][j] = _matrix[i][j];
						vvpPath[i][j] = i;
					}
					if (i == j)
					{
						vvDist[i][j] = 0;
					}
				}
			}
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (vvDist[k][j] != MAX_W && vvDist[i][k] != MAX_W && vvDist[i][k] + vvDist[k][j] < vvDist[i][j])
						{
							vvDist[i][j] = vvDist[i][k] + vvDist[k][j];
							vvpPath[i][j] = vvpPath[k][j];
						}
					}
				}
			}
		}
	private:
		vector<V> _vertexs;
		map<V, size_t> _vIndex;
		vector<vector<W>> _matrix;
	};
	void TestFloydWarShall()
	{
		const char* str = "12345";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.addEdge('1', '2', 3);
		g.addEdge('1', '3', 8);
		g.addEdge('1', '5', -4);
		g.addEdge('2', '4', 1);
		g.addEdge('2', '5', 7);
		g.addEdge('3', '2', 4);
		g.addEdge('4', '1', 2);
		g.addEdge('4', '3', -5);
		g.addEdge('5', '4', 6);
		vector<vector<int>> vvDist;
		vector<vector<int>> vvParentPath;
		g.FloydWarShall(vvDist, vvParentPath);
		// 打印任意两点之间的最短路径
		for (size_t i = 0; i < strlen(str); ++i)
		{
			g.PrinrtShotPath(str[i], vvDist[i], vvParentPath[i]);
			cout << endl;
		}
	}
	void TestGraphBellmanFord()
	{
		/*const char* str = "syztx";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.addEdge('s', 't', 6);
		g.addEdge('s', 'y', 7);
		g.addEdge('y', 'z', 9);
		g.addEdge('y', 'x', -3);
		g.addEdge('z', 's', 2);
		g.addEdge('z', 'x', 7);
		g.addEdge('t', 'x', 5);
		g.addEdge('t', 'y', 8);
		g.addEdge('t', 'z', -4);
		g.addEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		if (g.Bellman_Ford('s', dist, parentPath))
		{
			g.PrinrtShotPath('s', dist, parentPath);
		}
		else
		{
			cout << "存在负权回路" << endl;
		}*/
		//微调图结构，带有负权回路的测试
		const char* str = "syztx";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.addEdge('s', 't', 6);
		g.addEdge('s', 'y', 7);
		g.addEdge('y', 'x', -3);
		g.addEdge('y', 'z', 9);
		g.addEdge('y', 'x', -3);
		g.addEdge('y', 's', 1); // 新增
		g.addEdge('z', 's', 2);
		g.addEdge('z', 'x', 7);
		g.addEdge('t', 'x', 5);
		g.addEdge('t', 'y', -8); // 更改
		g.addEdge('t', 'z', -4);
		g.addEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		if (g.Bellman_Ford('s', dist, parentPath))
		{
		 g.PrinrtShotPath('s', dist, parentPath);
		}
		else
		{
		 cout << "存在负权回路" << endl;
		}
	}
	void TestGraphDijkstra()
	{
		const char* str = "syztx";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.addEdge('s', 't', 10);
		g.addEdge('s', 'y', 5);
		g.addEdge('y', 't', 3);
		g.addEdge('y', 'x', 9);
		g.addEdge('y', 'z', 2);
		g.addEdge('z', 's', 7);
		g.addEdge('z', 'x', 6);
		g.addEdge('t', 'y', 2);
		g.addEdge('t', 'x', 1);
		g.addEdge('x', 'z', 4);
		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrinrtShotPath('s', dist, parentPath);
		// 图中带有负权路径时，贪心策略则失效了。
		// 测试结果可以看到s->t->y之间的最短路径没更新出来
		/*const char* str = "sytx";
		 Graph<char, int, INT_MAX, true> g(str, strlen(str));
		 g.AddEdge('s', 't', 10);
		 g.AddEdge('s', 'y', 5);
		 g.AddEdge('t', 'y', -7);
		 g.AddEdge('y', 'x', 3);
		 vector<int> dist;
		 vector<int> parentPath;
		 g.Dijkstra('s', dist, parentPath);
		 g.PrinrtShotPath('s', dist, parentPath);*/
	}
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
	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
		graph<char, int> g(str, strlen(str));
		g.addEdge('a', 'b', 4);
		g.addEdge('a', 'h', 8);
		//g.AddEdge('a', 'h', 9);
		g.addEdge('b', 'c', 8);
		g.addEdge('b', 'h', 11);
		g.addEdge('c', 'i', 2);
		g.addEdge('c', 'f', 4);
		g.addEdge('c', 'd', 7);
		g.addEdge('d', 'f', 14);
		g.addEdge('d', 'e', 9);
		g.addEdge('e', 'f', 10);
		g.addEdge('f', 'g', 2);
		g.addEdge('g', 'h', 1);
		g.addEdge('g', 'i', 6);
		g.addEdge('h', 'i', 7);
		graph<char, int> kminTree;
		cout << "Kruskal:" << g.kruskal(kminTree) << endl;
		kminTree.print();
		graph<char, int> pminTree;
		cout << "Prim:" << g.Prim('a', pminTree) << endl;
		pminTree.print();
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
