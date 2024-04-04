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
    void PrintVertexesPower();
    bool IsRegular();
    bool IsDirected();
    void PrintSourcesAndDrains();
    void PrintNeighborsList();
  
private:
    void init();
    void initMatrix();
    void initEdges();
    void initVertexesPowerListFromMatrix();
    void initVertexesPowerListFromEdges();
    void initMatrixFromEdges();
    void initEdgesFromMatrix();
    int getVertexesCountFromEdges();
    int* getVertexesPowerCountFromEdges();
    int* getVertexesPowerCountFromMatrix();
    void dispose();
    void disposeMatrix();
    void disposeEdges();
    void disposeVertexesPowerList();
  
    int _vertexes;
    int _edges;
    int** _matrix;
    SEdge* _edge;
    int* _vertexesPowerList;
};
  
  
CGraph::CGraph()
    : _vertexes(0), _edges(0), _matrix(0), _edge(0), _vertexesPowerList(0) {}
  
CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _edges(edges), _matrix(0), _edge(0), _vertexesPowerList(0)
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
    initVertexesPowerListFromMatrix();
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
        for (int j = 0; j < _vertexes; ++j) 
        {
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
  
void CGraph::initVertexesPowerListFromMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _vertexesPowerList = new int[_vertexes];
    for (int i = 0 ; i < _vertexes; ++i) 
    {
        _vertexesPowerList[i] = 0;
        for (int j = 0; j <_vertexes; ++j)
        {
            _vertexesPowerList[i] = _vertexesPowerList[i] + (_matrix[i][j] != 0);
        }
    }
}

void CGraph::initMatrixFromEdges()
{
    disposeMatrix();
    _vertexes = getVertexesCountFromEdges();
    initMatrix();
    for (int i = 0; i < _edges; ++i)
    {
        _matrix[_edge[i].a - 1][_edge[i].b - 1] = _edge[i].w;
    }
}
  
int CGraph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
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
    disposeVertexesPowerList();
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

void CGraph::disposeVertexesPowerList()
{
    if (_vertexes != 0)
    {
        delete[] _vertexesPowerList;
        _vertexesPowerList = 0;
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
    return res;
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
 
 
// int* CGraph::getVertexesPowerCountFromEdges(int vertex, int edges) 
// {
//     int* ans = new int[vertex];
//     for (int i = 0; i < vertex; ++i) 
//     {
//        ans[i] = 0;
//     }
//     for (int i = 0; i < edges; ++i) 
//     {
//         ans[_edge[i].b - 1]++;
//         ans[_edge[i].a - 1]++;
//     }
//     return ans;
// }
 
void CGraph::PrintVertexesPower() 
{  
    disposeVertexesPowerList();
    initVertexesPowerListFromMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        std::cout << _vertexesPowerList[i] << " ";
    }
}

bool CGraph::IsRegular()
{
    disposeVertexesPowerList();
    initVertexesPowerListFromMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        if (_vertexesPowerList[0] != _vertexesPowerList[i])
        {
            return false;
        }
    }
    return true;
}
  
bool CGraph::IsDirected()
{

    for (int i = 0; i < _vertexes; ++i)
    {
        if (_matrix[i][i] > 0)
        {
            return false;
        }

    }
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = i + 1; j < _vertexes; ++j)
        {
            if (_matrix[i][j] != _matrix[j][i])
            {
                return true;
            }
        }
    }
    return false;
}

void CGraph::PrintSourcesAndDrains()
{
    int sourcesNumber = 0;
    int drainNumber = 0;
    bool isSource = false;
    bool isDrain = false;
    for (int i = 0; i < _vertexes; ++i)
    {
        isSource = true;
        isDrain = true;
        for (int j = 0; (j < _vertexes) && (isSource || isDrain); ++j)
        {
            if (_matrix[i][j] > 0) 
            {
                isDrain = false;
            }
            if (_matrix[j][i] > 0) 
            {
                isSource = false;
            }
        }
        if (isSource)
        {
            sourcesNumber++;
        }
        if (isDrain)
        {
            drainNumber++;
        }
    }
    std::cout << sourcesNumber << " ";
    for (int i = 0; i < _vertexes; ++i)
    {
        isSource = true;
        for (int j = 0; (j < _vertexes) && isSource; ++j)
        {
            if (_matrix[j][i] > 0) 
            {
                isSource = false;
            }
        }
        if (isSource)
        {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << "\n" << drainNumber << " ";
    for (int i = 0; i < _vertexes; ++i)
    {
        isDrain = true;
        for (int j = 0; (j < _vertexes) && isDrain; ++j)
        {
            if (_matrix[i][j] > 0) 
            {
                isDrain = false;
            }
        }
        if (isDrain)
        {
            std::cout << i + 1 << " ";
        }
    }
}

void CGraph::initVertexesPowerListFromEdges()
{
    initMatrixFromEdges();
    initVertexesPowerListFromMatrix();
}


void CGraph::PrintNeighborsList()
{
    if (_vertexesPowerList == 0)
    {
        if (_vertexes == 0)
        {
            initVertexesPowerListFromEdges();
        }
        else
        {
            initVertexesPowerListFromMatrix();
        }
    }
    for (int i = 0; i < _vertexes; ++i)
    {
        std::cout << _vertexesPowerList[i] << " ";
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrix[i][j] > 0)
            {
                std::cout << j + 1 << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    CGraph gph = CGraph();
    std:: cout << n << "\n";
    gph.ReadEdges(m);
    gph.PrintNeighborsList();
}