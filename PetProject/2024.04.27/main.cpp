//library for I/O from the console
#include<iostream>
//edge
struct SEdge {
	//start
	int a;
	//end
	int b;
	// weight
	int w;
	//constructor
	SEdge(int a = 0, int b = 0, int w = 0) : a(a), b(b), w(w) {}
	//copy constructor
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	//move constructor
	SEdge(SEdge&& src) throw()
	{
		a = src.a;
		b = src.b;
		w = src.w;
		src.a = 0;
		src.b = 0;
		src.w = 0;
	}
	//deconstructor
	~SEdge() {}
	//the output operator
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
	// assignment operator
	SEdge& operator=(const SEdge& edge)
	{
		if (&edge != this)
		{
			a = edge.a;
			b = edge.b;
			w = edge.w;
		}
	}
};
//graph
class CGraph {
public:
	//constructor
	CGraph(int n = 1) : _n(n), _matr(0) { initMatrix(); };
	//copy constructor
	CGraph(const CGraph& src) : _n(src._n) {
		initMatrix();
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _n; ++j)
			{
				_matr[i][j] = src._matr[i][j];
			}
		}
	}
	//move constructor
	CGraph(CGraph&& src) throw() 
	{
		_n = src._n;
		initMatrix();
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _n; ++j)
			{
				_matr[i][j] = src._matr[i][j];
			}
		}
		src.~CGraph();

	}
	//deconstructor
	~CGraph() { disposeMatrix(); }
	//reading a graph from an adjacency matrix
	void readMatrix();
	//reading a graph from the adjacency list
	void readAdj();
	//reading a graph from a list of edges
	void readEdges();
	//graph output to the adjacency matrix
	void printMatrix();
	//output graph to the adjacency list
	void printAdj();
	//outputting a graph to a list of edges
	void printEdges();
	//output of vertex degrees
	void printPowers();
	//is the graph complete?
	bool isFull();
	//is the graph oriented?
	bool isOriented();
	//is the graph regular?
	bool isRegular();
	//output MST using the algorithm of the Prime
   	 void printMSTPrima();
	//output MST using the Paint algorithm
    void printMSTKruskal();
	//assignment operator
	CGraph& operator=(const CGraph& src)
	{
		if (this != &src)
		{
			_n = src._n;
			initMatrix();
			for (int i = 0; i < _n; ++i)
			{
				for (int j = 0; j < _n; ++j)
				{
					_matr[i][j] = src._matr[i][j];
				}
			}
		}
	}
private:
	//number of edges
	int edgeNumber();
	//an ascending list of edges
	SEdge* sortedEdges();
	//allocating memory for the graph adjacency matrix and filling it with 0
	void initMatrix();
	//clearing the memory allocated for the adjacency matrix of the graph
	void disposeMatrix();
	//vertex degree
	int power(int vertex);
	//number of vertices
	int _n;
	//adjacency matrix
	int** _matr;
};

int CGraph::edgeNumber()
{
	int m = 0;
	for (int i = 0; i <_n; ++i)
	{
		for (int j = i + 1; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				m++;
			}
		}
	}
	return m;
}

SEdge* CGraph::sortedEdges()
{
	int m = edgeNumber();
	SEdge* ans = new SEdge[m];
	int tmp = 0;
	for (int i = 0; i <_n; ++i)
	{
		for (int j = i + 1; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				ans[tmp] = SEdge(i, j, _matr[i][j]);
				tmp++;
			}
		}
	}
	SEdge tmpEdge = SEdge();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			if (ans[j].w > ans[j + 1].w)
			{
				tmpEdge = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = tmpEdge;
			}
		}
	}
	return ans;
}

void CGraph::printMSTKruskal()
{
	if (isOriented()) 
	{
		std::cout << "Graph should not be oriented for Kruskal alghoritm";
	}
	int m = edgeNumber();
	SEdge* edges = sortedEdges();
	SEdge* ans = new SEdge[_n - 1];
	int ansTmp = 0;
	int* treeColor = new int[_n];
	for (int i = 0; i < _n; ++i)
	{
		treeColor[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		if (treeColor[a] != treeColor[b])
		{
			ans[ansTmp] = SEdge(a, b, w);
			ansTmp++;
			int oldColor = treeColor[b];
			int newColor = treeColor[a];
			//joining trees
			for (int j = 0; j < _n; ++j)
			{
				if (treeColor[j] == oldColor)
				{
					treeColor[j] = newColor;
				}
			}
		}
	}
	//converting and outputting MST
	int** ansMatr = new int*[_n];
	for (int i = 0 ; i < _n; ++i)
	{
		ansMatr[i] = new int[_n];
		for (int j = 0; j < _n; ++j)
		{
			ansMatr[i][j] = 0;
		}
	}
	
	for (int i = 0; i < _n - 1; ++i)
	{
		ansMatr[ans[i].a][ans[i].b] = ans[i].w;
		ansMatr[ans[i].b][ans[i].a] = ans[i].w;
	}
	
	for (int i = 0 ; i < _n; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < _n; ++j)
		{
			std::cout << ansMatr[i][j] << " ";
		}
	}
	for (int i = 0; i < _n; ++i)
	{
		delete[] ansMatr[i];
	}
	delete[] ansMatr;
}

void CGraph::initMatrix()
{
	_matr = new int* [_n];
	for (int i = 0; i < _n; ++i)
	{
		_matr[i] = new int[_n];
		for (int j = 0; j < _n; ++j)
		{
			_matr[i][j] = 0;
		}
	}
}

void CGraph::disposeMatrix()
{
	for (int i = 0; i < _n; ++i)
	{
		delete[] _matr[i];
	}
	delete[] _matr;
}

int CGraph::power(int vertex)
{
	int pw = 0;
	for (int j = 0; j < _n; ++j)
	{
		pw += (_matr[vertex][j] > 0);
	}
	return pw;
}

void CGraph::readMatrix()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			std::cin >> _matr[i][j];
		}
	}
}

void CGraph::readAdj()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	for (int i = 0; i < _n; ++i)
	{
		int m = 0;
		std::cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int k = 0;
			std::cin >> k;
			std::cin >> _matr[i][k - 1];
		}
	}
}

void CGraph::readEdges()
{
	disposeMatrix();
	std::cin >> _n;
	initMatrix();
	int m = 0;
	std::cin >> m;
	for (int k = 0; k < m; ++k)
	{
		int i = 0;
		int j = 0;
		std::cin >> i >> j;
		std::cin >> _matr[i - 1][j - 1];
	}
}

void CGraph::printMatrix()
{
	std::cout << _n << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			std::cout << _matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::printAdj()
{
	std::cout << _n << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		std::cout << power(i) << " ";
		for (int j = 0; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				std::cout << j + 1 << " " << _matr[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void CGraph::printEdges()
{
	std::cout << _n << " ";
	int m = 0;
	for (int i = 0; i < _n; m += power(i), ++i);
	std::cout << m << std::endl;
	for (int i = 0; i < _n; ++i)
	{
		for (int j = 0; j < _n; ++j)
		{
			if (_matr[i][j] != 0)
			{
				std::cout << i + 1 << " " << j + 1 << " " << _matr[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void CGraph::printPowers()
{
	for (int i = 0; i < _n; ++i)
	{
		std::cout << power(i) << " ";
	}
}

bool CGraph::isFull()
{
	if (!isOriented())
	{
		return false;
	}
	int m = 0;
	for (int i = 0; i < _n; m += power(i), ++i);
	return (m * 2 == _n * (_n - 1));
}

bool CGraph::isOriented()
{
	for (int i = 0; i < _n; ++i)
	{
		if (_matr[i][i] == 1)
		{
			return false;
		}
	}
	for (int i = 0; i < _n; ++i)
	{
		for (int j = i + 1; j < _n; ++j)
		{
			if (_matr[i][j] != _matr[j][i])
			{
				return true;
			}
		}
	}
	return false;
}

bool CGraph::isRegular()
{
	for (int i = 0; i < _n; ++i)
	{
		if (power(i) != power(0))
		{
			return false;
		}
	}
	return true;
}

void CGraph::printMSTPrima()
{
	//checking the orientation of the graph
	if (isOriented())
	{
		std::cout << "Graph should not be oriented for Prima algorithm";
	}
	int**ans = new int*[_n];
	bool* used = new bool[_n];
	int* priority = new int[_n];
	int* prev = new int[_n];
	//filling with initial values
	for (int i = 0; i < _n; ++i)
	{
		used[i] = 0;
		priority[i] = 100000;
		prev[i] = -1;
		ans[i] = new int[_n];
		for (int j = 0; j < _n; ++j)
		{
			ans[i][j] = 0;
		}
	}
	priority[0] = 0;
	for (int i = 0; i < _n; ++i) 
	{
		int v = -1;
		//looking for a priority vertex
		for (int j = 0; j < _n; ++j)
		{
			if (!used[j] && (v == -1 || priority[j] < priority[v]))
				v = j;
		}
		if (priority[v] == 100000) 
		{
			std::cout << "No MST!";
			return;
		}
		//adding it to the subtree
		used[v] = true;
		if (prev[v] != -1)
		{
			ans[v][prev[v]] = _matr[v][prev[v]];
			ans[prev[v]][v] = _matr[v][prev[v]];
		}
		//changing priorities based on the new subtree
		for (int to = 0; to < _n; ++to)
		{
			if (_matr[v][to] < priority[to]) 
			{
				priority[to] = _matr[v][to];
				prev[to] = v;
			}
		}
	}
	//output of the MST proximity matrix
	for (int i = 0; i < _n; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < _n; ++j)
		{
			std::cout << ans[i][j] << " ";
		}
	}
	for (int i = 0; i < _n; ++i)
	{
		delete[] ans[i];
	}
	delete[] ans;
	delete[] used;
	delete[] prev;
	delete[] priority;
}

int main(int argc, char* argv[])
{
	
	std::cout << "Graph should not be oriented" << std::endl;
	std::cout << "The weight of the edges should be from 0 to 10000" << std::endl;
	std::cout << "How do you want to set the graph?" << std::endl 
		<< "For the adjacency matrix, enter M." << std::endl 
		<< "For the adjacency list, enter A." << std::endl 
		<< "For the list of edges, enter E." << std::endl;
	char tipe = 0;
	std::cin >> tipe;
    CGraph gph = CGraph();
	if (tipe == 'M')
	{
		std::cout << "Enter the number of vertices and the adjacency matrix" << std::endl;
		gph.readMatrix();
	}
	else if (tipe == 'A')
	{
		std::cout << "Enter the number of vertices and the list of adjacencies with weights." << std::endl;
    	gph.readAdj();
	}
	else if (tipe == 'E')
	{
		std::cout << "Enter the number of vertices, the number of edges, and the list of edges with weights." << std::endl;
    	gph.readEdges();
	}
	else
	{
		std::cout << "Read the instructions carefully and try again((" << std::endl;
	}
	std::cout << "Write what algorithm to implement the search for the minimum spanning tree?" << std::endl;
	std::cout << "Write <<K>> - if you want the Kruskal algorithm" << std::endl;
	std::cout << "Write <<P>> - if you want the Prima algorithm" << std::endl;
	tipe = 0;
	std::cin >> tipe;
	if (tipe == 'K')
	{
		gph.printMSTKruskal();
	}
	else if (tipe == 'P')
	{
    	gph.printMSTPrima();
	}
	else
	{
		std::cout << "Read the instructions carefully and try again((" << std::endl;
	}
	return 0;
}
//edge output operator
std::ostream &operator<<(std::ostream &stream, const SEdge &edge)
{
	std::cout << edge.a << " " << edge.b << " " << edge.w << std::endl;
}
