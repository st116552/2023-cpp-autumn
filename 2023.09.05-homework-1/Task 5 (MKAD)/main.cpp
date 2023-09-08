#include <fstream>

using namespace std;

int main() 
{
    long long v, t;
    long long road = 109 * 1000000 + 1;
    ifstream fin;
    fin.open("input.txt");
    fin >> v >> t;
    fin.close();
    road = (road + v * t - 1) % 109 + 1;
    ofstream fout;
    fout.open("output.txt");
    fout << road;
    fout.close();
    return 0;
}