#include<iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	void PrintMatrix();
	void PrintEdges();
	void ReadMatrix(int vertexes);
	void ReadEdges(int edges, bool haveweight = false);
	int getEdgesCountFromMatrix();

private:
	void init();
	void initMatrix();
	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	int getVertexesCountFromEdges();
	void dispose();
	void disposeMatrix();
	void disposeEdges();

	int _vertexes;
	int _edges;
	int** _matrix;
	SEdge* _edge;
};


CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(0), _edge(0) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(0), _edge(0)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::PrintMatrix()
{
	if (_matrix == 0)
	{
		if (_edge == 0)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	if (_edge == 0)
	{
		if (_matrix == 0)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::ReadMatrix(int vertexes)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
}

void CGraph::ReadEdges(int edges, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		std::cin >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			std::cin >> _edge[i].w;
		}
	}
}

void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int*[_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes];
        for (int j = 0; j < _vertexes; ++j) {
            _matrix[i][j] = 0;
        }
	}
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = i; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
}

void CGraph::disposeMatrix()
{
	if (_matrix != 0)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = 0;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != 0)
	{
		delete[] _edge;
		_edge = 0;
	}
}

void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

std::ostream & operator<<(std::ostream & stream, const SEdge & edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

int main() {
    int n = 0;
    std::cin >> n;
    CGraph gph = CGraph(n, 0);
    gph.ReadMatrix(n);
    std::cout << gph.getEdgesCountFromMatrix();
}