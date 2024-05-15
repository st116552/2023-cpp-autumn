//библиотека для ввода-вывода из-в консоль
#include<iostream>
//ребро
struct SEdge {
	//начало
	int a;
	//конец
	int b;
	//вес
	int w;
	//конструктор
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	//конструктор копирования
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	//деконструктор
	~SEdge() {}
	//оператор вывода
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};
//граф
class CGraph {
public:
	//конструктор
	CGraph(int n = 1) : _n(n), _matr(0) { initMatrix(); };
	//конструктор копирования
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
	//деконструктор
	~CGraph() { disposeMatrix(); }
	//считывание графа из матрицы смежности
	void readMatrix();
	//считывание графа из списка смежности
	void readAdj();
	//считывание графа из списка ребер
	void readEdges();
	//вывод графа в матрицу смежности
	void printMatrix();
	//вывод графа в список смежности
	void printAdj();
	//вывод графа в список ребер
	void printEdges();
	//вывод степеней вершин
	void printPowers();
	//полный ли граф?
	bool isFull();
	//ориентированный ли граф?
	bool isOriented();
	//регулярный ли граф?
	bool isRegular();
	//вывести MST используя алогритм Прима
    void printMSTPrima();
	//вывести MST используя алогритм Краскала
    void printMSTKruskal();
private:
	//кол-во ребер
	int edgeNumber();
	//отсортированный по возрастанию список ребер
	SEdge* sortedEdges();
	//выделение памяти под матрицу смежности графв и заполнение ее 0и
	void initMatrix();
	//очищение памяти выделенной под матрицу смежности графа
	void disposeMatrix();
	//степень вершны vertex
	int power(int vertex);
	//кол-во вершин
	int _n;
	//матрица смежности
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
			//обьединяем деревья
			for (int j = 0; j < _n; ++j)
			{
				if (treeColor[j] == oldColor)
				{
					treeColor[j] = newColor;
				}
			}
		}
	}
	//преобразование и вывод MST
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
	//проверка ориентированности графа
	if (isOriented()) 
	{
		std::cout << "Graph should not be oriented for Prima alghoritm";
	}
	int**ans = new int*[_n];
	bool* used = new bool[_n];
	int* priority = new int[_n];
	int* prev = new int[_n];
	//заполнение начальными значениями
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
		//ищем приоритетную вершину
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
		//добавляем ее в поддерево
		used[v] = true;
		if (prev[v] != -1)
		{
			ans[v][prev[v]] = _matr[v][prev[v]];
			ans[prev[v]][v] = _matr[v][prev[v]];
		}
		//меняем приоритеты исходя из нового поддерева
		for (int to = 0; to < _n; ++to)
		{
			if (_matr[v][to] < priority[to]) 
			{
				priority[to] = _matr[v][to];
				prev[to] = v;
			}
		}
	}
	//вывод матрицы смежости MST
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
//оператор вывода ребра
std::ostream &operator<<(std::ostream &stream, const SEdge &edge)
{
    std::cout << edge.a << " " << edge.b << " " << edge.w << std::endl;
}
