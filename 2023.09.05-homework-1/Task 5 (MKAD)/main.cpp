#include <fstream>

using namespace std;

int main() 
{
    int const roadLength = 109;
    long long v = 0;
    long long t = 0;
    long long road = roadLength * 1000000 + 1;
    ifstream fin;
    fin.open("input.txt");
    fin >> v >> t;
    fin.close();
    road = (road + v * t - 1) % roadLength + 1;
    ofstream fout;
    fout.open("output.txt");
    fout << road;
    fout.close();
    return 0;
}